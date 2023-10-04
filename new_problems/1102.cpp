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
    int N;
    cin >> N;
    vvi adj(N, vi(N, 0));
    for(auto &v: adj){
        for(auto &x: v){
            cin >> x;
        }
    }
    string s; cin >> s;
    int state = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == 'Y') state |= (1 << i);
    }
    int P; cin >> P;
    vi visited(2 << N, 0);
    vi dp(2 << N, 1e9);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, state});
    int ans = 1e9;
    while(!pq.empty()){
        auto[d, x] = pq.top(); pq.pop();
        if(dp[x] < d) continue;
        int n = __popcount(x);
        if(P <= n) ans = min(ans, d);
        for(int i = 0; i < N; i++){
            if(x & (1 << N)) continue;
            int next = x | (1 << i);
            int next_d = 1e9;
            for(int j = 0; j < N; j++){
                if(x & (1 << j)) next_d = min(next_d, d + adj[j][i]);
            }
            if(next_d < dp[next]){
                dp[next] = next_d;
                pq.push({dp[next], next});
            }
        }
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}     