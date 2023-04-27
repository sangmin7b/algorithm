#include<bits/stdc++.h>

using namespace std;
int dp[3][100000];
int main(int argc, const char** argv) {
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    int N;
    cin >> N;
    for(int i=1;i<N;i++){
        dp[0][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
        dp[1][i] = dp[0][i-1] + dp[2][i-1];
        dp[2][i] = dp[0][i-1] + dp[1][i-1];
        dp[0][i] %= 9901;
        dp[1][i] %= 9901;
        dp[2][i] %= 9901;
    }

    cout << (dp[0][N-1] + dp[1][N-1] + dp[2][N-1] ) % 9901 << "\n";
    

    return 0;
}