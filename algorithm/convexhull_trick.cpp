#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

double cross(pl &p1, pl &p2){
    return (double) (p1.second - p2.second) / (p2.first - p1.first); 
};

// dp[i] = max(dp[j] + f(sum(x[j+1..i])))
// dp[i] = max(dp[j] + f(sum[i] - sum[j]))
// dp[i] = max(dp[j] + a(sum[i] - sum[j]) ^ 2 + b(sum[i] - sum[j]) + c)
// dp[i] = max(dp[j] + a * sum[i] ^ 2 - 2 * a * sum[i] * sum[j] + a * sum[j] ^ 2 + b * sum[i] - b * sum[j] + c)
// dp[i] = a * sum[i] ^ 2 + b * sum[i] + c + max(-2 * a * sum[j] * sum[i] + dp[j] + a * sum[j] ^ 2 - b * sum[j])

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    int a, b, c; cin >> a >> b >> c;
    vl sum(N + 1, 0);
    vl dp(N + 1, 0);
    vector<pl> dq(N);
    int s = 0, e = 0;
    for(int i = 1; i <= N; i++){
        cin >> sum[i]; sum[i] += sum[i - 1];
    }    
    for(int i = 1; i <= N; i++){
        ll v = a * sum[i] * sum[i] + b * sum[i] + c; 
        while(s + 1 < e && cross(dq[s], dq[s+1]) < sum[i]){   
            s++;
        }
        if(s < e && 0 < dq[s].first * sum[i] + dq[s].second){
            v += dq[s].first * sum[i] + dq[s].second;
        }
        dp[i] = v;
        pl p = {-2 * a * sum[i], dp[i] + a * sum[i] * sum[i] - b * sum[i]};
        while(s + 1 < e && cross(dq[e-1], p) < cross(dq[e-2], dq[e-1])){
            e--;
        }
        dq[e++] = p;
    }
    cout << dp[N];
    return 0;
}   