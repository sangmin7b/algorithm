#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, M;
vvi board;
vvi visited;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int bfs(int r, int c, int h){
    visited[r][c] = 1;
    if(h <= board[r][c]){
        return 0;
    }
    bool valid = true;
    int ans = 0;
    queue<pi> q;
    q.push({r, c});
    while(!q.empty()){
        ans++;
        tie(r, c) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || N <= nr || nc < 0 || M <= nc){
                valid = false;
                continue;
            }
            if(visited[nr][nc] || h <= board[nr][nc])
                continue;
            visited[nr][nc] = 1;
            board[nr][nc]++;
            q.push({nr, nc});
        }
    }
    if(valid){
        return ans;
    }else{
        return 0;
    }
}

int main(int argc, const char** argv) {
    cin >> N >> M;
    board = vvi(N, vi(M,0));
    for(int i=0;i<N;i++){
        string s; cin >> s;
        for(int j=0;j<M;j++){
            board[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for(int h=1;h<=9;h++){
        visited = vvi(N, vi(M, 0));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(visited[i][j])
                    continue;
                ans+= bfs(i, j, h);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}     