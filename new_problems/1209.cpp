#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N;

ll solve(vl &A){
    vl sorted(A);
    sort(sorted.begin(), sorted.end());
    vvl dp(N, vl(N, 1e15));
    dp[0][0] = abs(A[0] - sorted[0]);
    for(int j = 1; j < N; j++){
        dp[0][j] = min(dp[0][j-1], abs(A[0] - sorted[j]));
    }
    for(int i = 1; i < N; i++){
        dp[i][0] = dp[i-1][0] + abs(A[i] - sorted[0]);
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j] + abs(A[i] - sorted[j])); 
        }
    }
    return *min_element(dp[N-1].begin(), dp[N-1].end());
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    vl A(N), B(N); 
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        A[i] = x; B[i] = -x;
    }
    cout << min(solve(A), solve(B));
    return 0;
}       