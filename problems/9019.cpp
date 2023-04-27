#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int op_d(int x){
    x <<= 1;
    if(x >= 10000){
        x -= 10000;
    }
    return x;
};
int op_s(int x){
    return x ? x - 1 : 9999;
};
int op_l(int x){
    return (x / 1000) + (x % 1000 * 10);
};
int op_r(int x){
    return (x % 10) * 1000 + (x / 10);
};

char op_name[4] = {'D', 'S', 'L', 'R'};

void solve(){
    vector<pi> prev(10000,{-1,0});
    int a, b;
    cin >> a >> b;
    queue<int> q;
    q.push(a);
    prev[a] = {a, -1};
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == b){
            break;
        }
        int results[4] = {op_d(now),op_s(now),op_l(now),op_r(now)};
        for(int i=0;i<4;i++){
            int next = results[i];
            if(prev[next].first == -1){
                prev[next] = {now, i};
                q.push(next);
            }
        }
    }
    stack<int> s;
    for(int p=b; p != prev[p].first; p=prev[p].first){
        s.push(prev[p].second);
    }
    while(!s.empty()){
        cout << op_name[s.top()];
        s.pop();
    }
    cout << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}     