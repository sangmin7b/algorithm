#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> memo(N+1,0);
    int M = 10007;
    memo[1] = 1;
    memo[2] = 3;
    for(int i=3;i<=N;i++){
        memo[i] = memo[i-1] + 2 * memo[i-2];
        memo[i] %= M;
    }
    int ans = memo[N];
    cout << ans;
    return 0;
}