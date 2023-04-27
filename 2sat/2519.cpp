#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
int ccw(pii A, pii B, pii C){
    pii v_ab = {B.first - A.first, B.second - A.second};
    pii v_bc = {C.first - B.first, C.second - B.second};
    return v_ab.first * v_bc.second - v_ab.second * v_bc.first;
}

bool is_crossing(pair<pii, pii> A, pair<pii, pii> B){
    int c1 = ccw(A.first, A.second, B.first);
    int c2 = ccw(A.first, A.second, B.second);
    int c3 = ccw(B.first, B.second, A.first);
    int c4 = ccw(B.first, B.second, A.second);

    return ((c1 ^ c2) & (c3 ^ c4)) < 0  ;
}

vector<vector<int>> adj;
vector<vector<int>> rev;

int _not(int k){
    return k ^ 1;
}

void add_edge(int from, int to){
    adj[from].push_back(to);
    rev[to].push_back(from);
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<pair<pii, pii>> sticks;
    adj = vector<vector<int>>(6 * N, vector<int>());
    rev = vector<vector<int>>(6 * N, vector<int>());

    for(int i=0;i<3 * N;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sticks.push_back({{x1, y1}, {x2, y2}});        
    }
    for(int i=0;i<3 * N - 1;i++){
        for(int j=i+1;j<3 * N;j++){
            pair<pii, pii> s1 = sticks[i];
            pair<pii, pii> s2 = sticks[j];
            if(is_crossing(s1, s2)){
                add_edge(_not(2 * i), 2 * j);
                add_edge(_not(2 * j), 2 * i);
            }
        }
    }

    for(int i=0;i<N;i++){
        int n = 3 * i;
        int l1 = 2 * n;
        int l2 = 2 * (n + 1);
        int l3 = 2 * (n + 2);
        
        add_edge(l1, _not(l2));
        add_edge(l1, _not(l3));
        add_edge(l2, _not(l1));
        add_edge(l2, _not(l3));
        add_edge(l3, _not(l1));
        add_edge(l3, _not(l2));
    }

    stack<int> visit_order;
    vector<bool> visited1(6 * N, 0);
    function<void(int)> dfs1 = [&](int x){
        visited1[x] = 1;
        for(int next: adj[x]){
            if(!visited1[next]){
                dfs1(next);
            }
        }
        visit_order.push(x);
    };

    for(int i=0;i<6 * N;i++){
        if(!visited1[i]){
            dfs1(i);
        }
    }

    vector<int> visited2(6 * N, 0);
    function<void(int, int)> dfs2 = [&](int x, int color){
        visited2[x] = color;
        for(int next: rev[x]){
            if(!visited2[next]){
                dfs2(next, color);
            }
        }
    };
    int color = 1;
    while(!visit_order.empty()){
        int x = visit_order.top();
        visit_order.pop();
        if(visited2[x]) continue;
        dfs2(x, color);
        color++;
    }
    bool is_possible = true;
    for(int i=0;i<3 * N;i++){
        if(visited2[2 * i] == visited2[2 * i + 1]){
            is_possible = false;
            break;
        }
    }

    vector<int> is_removed(6 * N, -1);
    vector<pii> v;
    for(int i=0;i< 6 * N;i++){
        v.push_back({visited2[i], i});
    }
    sort(v.begin(), v.end());
    for(pii p:v){
        int x = p.second;
        if(is_removed[x] == -1){
            is_removed[x] = 0;
            is_removed[_not(x)] = 1;
        }
    }

    int removed_count = 0;
    for(int i=0;i<3*N;i++){
        if(is_removed[2 * i]){
            removed_count++;
        }
    }

    if(is_possible){
        cout << removed_count << "\n";
        for(int i=0;i<3*N;i++){
            if(is_removed[2 * i]){
                cout << i + 1 << " ";
            }
        }
    }else{
        cout << -1;       
    }

    return 0;
}