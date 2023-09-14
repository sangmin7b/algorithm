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
    int primes[7] = {2, 3, 5, 7, 11, 13, 17};
    double a, b; cin >> a >> b;
    a /= 100; b /= 100;
    double ans = 0;
    vector<vector<double>> dp(2, vector<double>(20, 0));
    dp[0][1] = a;
    dp[0][0] = 1 - a;
    dp[1][1] = b;
    dp[1][0] = 1 - b;
    for(int i = 2; i <= 18; i++){
        for(int j = i; 1 <= j; j--){
            dp[0][j] = dp[0][j-1] * a + dp[0][j] * (1 - a);
        }
        dp[0][0] = dp[0][0] * (1 - a);
        for(int j = i; 1 <= j; j--){
            dp[1][j] = dp[1][j-1] * b + dp[1][j] * (1 - b);
        }
        dp[1][0] = dp[1][0] * (1 - b);
    }
    for(int p : primes){
        ans += dp[0][p];
        ans += dp[1][p];
    }
    for(int p : primes){
        for(int q : primes){
            ans -= dp[0][p] * dp[1][q];
        }
    }
    cout.precision(12);
    cout << ans;
    return 0;
}     