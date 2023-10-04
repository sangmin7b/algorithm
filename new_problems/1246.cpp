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
    ll N, M; cin >> N >> M;
    vl cnt(1000002, 0);
    cnt[0] = M;
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        cnt[x+1]--;
    }
    for(int i = 0; i < 1000000; i++){
        cnt[i+1] += cnt[i];
    }
    ll ans = 0;
    ll p = 0;
    for(int i = 1; i <= 1000000; i++){
        if(ans < min(N, cnt[i]) * i){
            ans = min(N, cnt[i]) * i;
            p = i;
        }
    }
    cout << p << " " << ans;
    return 0;
}     