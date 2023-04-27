#include<bits/stdc++.h>

using namespace std;

int dp[101][10001];
int INF = 123456789;


int solve(int m, int n){
    if(m > n){
        return solve(n, m);
    }
    if(dp[m][n] > -1){
        return dp[m][n];
    }
    if(n % m == 0){
        dp[m][n] = n / m;
        return n / m;
    }
    int ans0 = 1 + solve(m, n - m);
    if(ans0 < 4 * n / m){
        dp[m][n] = ans0;
        return ans0;
    }
   
    int ans = INF;
    for(int i=m/2;i>=1;i--){
        int ans2 = solve(i, n) + solve(m - i, n);
        ans = min(ans, ans2);
    }
    for(int i=n/2;i>=1;i--){
        int ans2 = solve(m, i) + solve(m, n - i);
        ans = min(ans, ans2);
    }
    dp[m][n] = ans;
    return ans;
}

int main(int argc, char const *argv[]){
    for(int i=0;i<101;i++){
        for(int j=0;j<10001;j++){
            dp[i][j] = -1;
        }
    }
    int n, m;
    cin >> n >> m;
    cout << solve(m, n) << "\n";
    return 0;
}
