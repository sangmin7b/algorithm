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
    ll L, K, C; cin >> L >> K >> C;
    C = min(C, K);
    vl positions(K);
    for(auto &x : positions) cin >> x;
    positions.push_back(L);
    sort(positions.begin(), positions.end());
    positions.resize(unique(positions.begin(), positions.end()) - positions.begin());
    ll lo = 0, hi = L;
    ll ans = L;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        ll p = L;
        int idx = positions.size();
        for(int i = 0; i < C && 0 < idx; i++){
            while(0 < idx && (p - mid) <= positions[idx - 1]){
                idx--;
            }
            p = positions[idx];            
        }
        if(p <= mid){
            hi = mid;
            ans = p;
        }else{
            lo = mid + 1;
        }
    }
    cout << lo << " " << ans;  
    return 0;
}     