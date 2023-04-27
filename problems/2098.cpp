#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> W;
int visited_all;
bool is_visited(int visited, int n){
    return (visited & (1<<n));
}

int visit(int visited, int n){
    return (visited | (1<<n));
}

// DP[visited][x][end];
int DP[16][16][UINT16_MAX];

//solve(0, i, i);
int solve(int visited, int x, int end){
    if(DP[x][end][visited]){
        return DP[x][end][visited];
    }
    if((visited ^ (1<<end)) == visited_all){
        if(W[x][end]){
            return W[x][end];
        }
        return INT32_MAX;
    }
    int res = INT32_MAX;
    for(int next=0;next<W.size();next++){
        if((next == end) || (W[x][next] == 0) || is_visited(visited, next)){
            continue;
        }
        int s = solve(visit(visited, next), next, end);
        if(s == INT32_MAX){
            continue;
        }
        res = min(res, W[x][next] + s);
    }
    DP[x][end][visited] = res;
    return res;
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        visited_all |= (1<<i);
    }
    W = vector<vector<int>>(N, vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> W[i][j];
        }
    }
    int ans = INT32_MAX;
    for(int i=0;i<N;i++){
        ans = min(ans, solve(0,i,i));
    }
    cout << ans;
    return 0;
}