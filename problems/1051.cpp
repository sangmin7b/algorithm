#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int board[50][50];
int N, M, K;

int solve(){
    for(int w=K;0<w;w--){
        for(int i=0;i<N+1-w;i++){
            for(int j=0;j<M+1-w;j++){
                if(board[i][j] == board[i+w-1][j] && 
                    board[i][j] == board[i][j+w-1] &&
                    board[i][j] == board[i+w-1][j+w-1]
                ){
                    return w*w;
                }
            }
        }

    }
    return 0;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s; cin >> s;
        for(int j=0;j<M;j++){
            board[i][j] = s[j] - '0';
        }
    }
    K = min(N, M);
    cout << solve();
    return 0;
}     