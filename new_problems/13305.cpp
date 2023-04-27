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
    int N; cin >> N;
    vl dist(N,0);
    vl cost(N, 0);
    for(int i=0;i<N-1;i++){
        cin >> dist[i];
    }
    for(int i=0;i<N;i++){
        cin >> cost[i];
    }
    cost[N-1] = 0;
    ll ans = 0;
    int idx = 0;
    while(idx < N - 1){
        int next_idx = idx + 1;
        ll d = dist[idx];
        while(cost[idx] <= cost[next_idx]){
            d += dist[next_idx];
            next_idx++;
        }
        ans += d * cost[idx];
        idx = next_idx;
    }
    cout << ans;
    return 0;
}     