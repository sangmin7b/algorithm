#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<int> dist(N,-1);
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    return 0;
}
