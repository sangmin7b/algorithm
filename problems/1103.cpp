#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int dp[50][50];
char board[50][50];
int visited[50][50];
int N, M;

void dfs(int r, int c){
    if(board[r][c] == 'H'){
        dp[r][c] = 0;
        visited[r][c] = 2;
        return;
    }
    dp[r][c] = 1;
    visited[r][c] = 1;
    int x = board[r][c] - '0';
    int dr[4] = {0, x, 0, -x};
    int dc[4] = {x, 0, -x, 0};
    for(int i = 0; i < 4; i++){
        int rr = r + dr[i];
        int cc = c + dc[i];
        if(0 <= rr && rr < N && 0 <= cc && cc < M){
            if(visited[rr][cc] == 1){
                dp[r][c] = -1;
                visited[r][c] = 2;
                return;
            }
            if(!visited[rr][cc]){
                dfs(rr, cc);
            }
            if(dp[rr][cc] == -1){
                dp[r][c] = -1;
                visited[r][c] = 2;
                return;
            }
            dp[r][c] = max(dp[r][c], dp[rr][cc] + 1); 
        }
    }    
    visited[r][c] = 2;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < M; j++){
            board[i][j] = s[j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]) continue;
            dfs(i, j);
        }
    }
    cout << dp[0][0];
    return 0;
}     