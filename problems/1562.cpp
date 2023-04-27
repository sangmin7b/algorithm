#include<bits/stdc++.h>
#include <bitset>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int M = 1e9;
vector<vvi> dp (101, vvi(10, vi(1<<10,-1)));

int solve(int n,int prev, bitset<10> state){
    int s = (int)state.to_ulong();
    int zeros = 10 - state.count();
    if(n == 0){
        if(zeros == 0){
            return 1;
        }
        return 0;
    }
    if(dp[n][prev][s] != -1){
        return dp[n][prev][s];
    }
    if(n < zeros){
        dp[n][prev][s] = 0;
        return 0;
    }    
    int cnt = 0;
    for(int i=prev-1;i<=prev+1;i+=2){
        if(i < 0 || 9 < i){
            continue;
        }
        auto s2 = state;
        cnt += solve(n-1, i, s2.set(i));
        if(M <= cnt){
            cnt -= M;
        }
    }
    dp[n][prev][s] = cnt;
    return cnt;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    int ans = 0;
    for(int i=1;i<10;i++){
        ans += solve(N-1, i, bitset<10>(1<<i));
        if(M <= ans){
            ans -= M;
        }
    }
    cout << ans << "\n";
    return 0;
}