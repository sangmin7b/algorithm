#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n, ll k){
    ll ans = 1;
    k = min (k, n - k);
    for(ll i=0;i<k;i++){
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}


int main(int argc, const char** argv) {
    while (1){
        ll n,k;
        cin >> n >> k;
        if(n == 0 && k == 0){
            break;
        }
        cout << solve(n, k) << "\n";
    }
    

    return 0;
}