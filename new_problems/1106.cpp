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
    int C, N; cin >> C >> N;
    vi dp(1001, 1e9);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        int c, d; cin >> c >> d;
        for(int j = 0; j < d; j++){
            dp[j] = min(dp[j], c);
        }
        for(int j = 0; j + d <= C; j++){
            dp[j+d] = min(dp[j+d], dp[j] + c);
        }
    }
    cout << dp[C];        
    return 0;
}     