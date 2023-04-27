#include<bits/stdc++.h>
using namespace std;
using ti_3 = tuple<int, int, int>;
void solve(){
    int N, M, W;
    cin >> N >> M >> W;
    vector<ti_3> edges;
    vector<int> dist(N, 0);
    for(int i=0;i<M+W;i++){
        int s, e, t;
        cin >> s >> e >> t;
        s--; e--;
        if(i < M){
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }else{
            edges.push_back({s, e, -t});
        }
    }
    bool n_cycle = false;
    for(int i=0;i<N;i++){
        for(auto edge: edges){
            int s, e, t;
            tie(s, e, t) = edge;
            if(dist[e] > dist[s] + t){
                if(i == N - 1){
                    n_cycle = true;
                }
                dist[e] = dist[s] + t;            
            }
        }
    }    
    if(n_cycle)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main(int argc, const char** argv) {
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}