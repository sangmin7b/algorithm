#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll sol(ll N, ll x){
    ll sum = 0;
    for(ll i=1;i<=N;i++){
        sum += min(x/i, N);
    }   
    return sum; 
}

int main(int argc, const char** argv) {
    ll N, K;
    cin >> N >> K;
    ll l = 1, r = N*N;
    while(l < r){
        ll mid = (l + r)/2;
        if(sol(N, mid) < K){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    ll ans = l;
    cout << ans;
    return 0;
}