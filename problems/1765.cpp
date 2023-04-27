#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vi nums;
vi visited;
vvi adj;

class dsu{
    vector<int> parent;
    vector<int> size;
    public:
        int find(int a){
            if(parent[a] == a){
                return a;
            }
            parent[a] = find(parent[a]);
            return parent[a];
        }

        void union_set(int a, int b){
            int p1 = find(a);
            int p2 = find(b);
            if(p1 != p2){
                if(size[p1] < size[p2]){
                    swap(p1, p2);
                }
                parent[p2] = p1;
                size[p1] += size[p2];
            }
        }

        dsu(int N){
            parent = vector<int>(N,0);
            size = vector<int>(N, 1);
            for(int i=0;i<N;i++){
                parent[i] = i;
            }
        }
};

dsu d(1000);

void bfs(int x, int team1){
    visited[x] = 1;
    queue<int> q;
    q.push(x);
    int team[2] = {team1, -1};
    int turn = 1;
    while(!q.empty()){
        int size = q.size();
        while(size){
            vi unvisited;
            int now = q.front();
            q.pop();
            size--;
            for(int next: adj[now]){
                if(!visited[next]){
                    unvisited.push_back(next);
                }
            }
            if(unvisited.empty()){
                continue;
            }
            if(team[turn] == -1){
                team[turn] = d.find(unvisited[0]);
            }
            for(int next: unvisited){
                visited[next] = 1;
                q.push(next);
                d.union_set(team[turn], next);        
            }
        }   
        turn = turn ^ 1;
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    nums = vi(N,0);
    adj = vvi(N, vi());
    for(int i=0;i<M;i++){
        char type;
        int p, q;
        cin >> type >> p >> q;
        p--; q--;
        if(type == 'F'){
            d.union_set(p, q);
            continue;
        }
        adj[p].push_back(q);
        adj[q].push_back(p);        
    }
    visited = vi(N, 0);
    for(int i=0;i<N;i++){
        if(!visited[i]){
            bfs(i, d.find(i));
        }
    }
    set<int> s;
    for(int i=0;i<N;i++){
        s.insert(d.find(i));
    }
    cout << s.size() << "\n";
    return 0;
}     