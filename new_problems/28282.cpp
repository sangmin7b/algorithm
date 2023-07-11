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
    int N, K; cin >> N >> K;
    vi cnt(K + 1, 0);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        cnt[x]++;
    }   
    ll ans = 0; 
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        ans += N - cnt[x];
    }
    cout << ans;
    return 0;
}     