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
    int n, r, c; cin >> n >> r >> c;
    vvi board(r, vi(c, 0));
    int ans = min(min(r, c), (n + 1) / 2);
    int cnt = 2 * ans - 1;
    for(int i = 0; i < ans; i++){
        board[i][0] = 1;
        board[0][i] = 1;
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!board[i][j] && cnt < n){
                board[i][j] = 1;
                cnt++;
            }
        }
    }
    cout << ans << "\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << (board[i][j] ? '#' : '.');
        }
        cout << "\n";
    }
    return 0;

}      