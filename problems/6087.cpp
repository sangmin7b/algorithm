#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int W, H; cin >> W >> H;
    vvi board(H, vi(W, 0));
    vector<pi> C;
    for(int i = 0; i < H; i++){
        string s; cin >> s;
        for(int j = 0; j < W; j++){
            if(s[j] == '*'){
                board[i][j] = 1;
            }
            if(s[j] == 'C'){
                C.push_back({i, j});
            }
        }
    }
    vvi dist(H, vi(W, 1e9));
    queue<pi> q;
    dist[C[0].first][C[0].second] = 0;
    q.push(C[0]);
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        int d = dist[r][c];
        for(int dc = -1; dc <= 1; dc += 2){
            int c2 = c + dc;
            while(0 <= c2 && c2 < W && board[r][c2] != 1 && dist[r][c2] >= d + 1){
                if(dist[r][c2] > d + 1)
                    q.push({r, c2});
                dist[r][c2] = d + 1;
                c2 += dc;
            }
        }
        for(int dr = -1; dr <= 1; dr += 2){
            int r2 = r + dr;
            while(0 <= r2 && r2 < H && board[r2][c] != 1 && dist[r2][c] >= d + 1){
                if(dist[r2][c] > d + 1)
                    q.push({r2, c});
                dist[r2][c] = d + 1;
                r2 += dr;
            }
        }
    }
    cout << dist[C[1].first][C[1].second] - 1;
    return 0;
}     