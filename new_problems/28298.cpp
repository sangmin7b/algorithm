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
    int N, M, K;
    cin >> N >> M >> K;
    vvi board(N, vi(M, 0));
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < M; j++){
            board[i][j] = s[j] - 'A';
        }
    }
    int repainted = 0;
    vvi ans(K, vi(K, 0));
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            vi cnt(26, 0);
            for(int tile_i = 0; tile_i < N / K; tile_i++){
                for(int tile_j = 0; tile_j < M / K; tile_j++){
                    cnt[board[tile_i * K + i][tile_j * K + j]]++;
                }
            }
            int max_idx = 0;
            int max_cnt = 0;
            for(int k = 0; k < 26; k++){
                if(max_cnt < cnt[k]){
                    max_cnt = cnt[k];
                    max_idx = k;
                }
            }
            repainted += (M / K * N / K) - max_cnt;
            ans[i][j] = max_idx;
        }
    }
    cout << repainted << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << (char)('A' + ans[i % K][j % K]);
        }
        cout << "\n";
    }
    return 0;
}     