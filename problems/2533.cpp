#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<vector<int>> c;
int dp[1000000][2];

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    c = vector<vector<int>>(N,vector<int>(0));
    for(int i=0;i<N-1;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        c[y].push_back(x);
        c[x].push_back(y);
    }
    vector<bool> visited(N,0);
    function<void(int)> dfs = [&](int x){
        if(visited[x]){
            return;
        }
        visited[x] = true;
        dp[x][0] = 0;
        dp[x][1] = 1;
        for(int i: c[x]){
            if(visited[i]) continue;
            dfs(i);
            dp[x][0] += dp[i][1];
            dp[x][1] += min(dp[i][0], dp[i][1]);
        }
        return;
    };
    dfs(0);
    int ans = min(dp[0][0], dp[0][1]);
    cout << ans;
    return 0;
}