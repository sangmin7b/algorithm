#include <algorithm>
#include<bits/stdc++.h>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> dist(N,vector<int>(N,M+1));
    vector<int> items(N);
    for(int i=0;i<N;i++){
        cin >> items[i];
    }
    for(int i=0;i<R;i++){
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        dist[u][v] = l;
        dist[v][u] = l;
    }
    for(int i=0;i<N;i++){
        dist[i][i] = 0;
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<int> scores;
    transform(dist.begin(), dist.end(), back_inserter(scores), [=](vector<int> &v){
        return inner_product(v.begin(), v.end(), items.begin(), 0, plus<>{}, 
        [=](int d, int n){
            if(d>M) 
                return 0;
            return n;}
        );
    });
    cout << *max_element(scores.begin(), scores.end());
    return 0;
}