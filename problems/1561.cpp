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
    ll N, M; cin >> N >> M;
    vl T(M);
    for(ll &x : T){
        cin >> x;
    }
    ll lo = 0, hi = 1e18;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(ll t : T){
            cnt += mid / t + 1;
        }        
        if(cnt < N){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    ll cnt = 0;   
    for(ll t : T){
        cnt += lo / t + 1;
    }        
    int ans = -1;
    for(int i = M - 1; 0 <= i; i--){
        if(lo % T[i] == 0){
            if(cnt == N){
                ans = i;
                break;
            }
            cnt--;
        }
    }
    cout << ans + 1;
    return 0;
}     