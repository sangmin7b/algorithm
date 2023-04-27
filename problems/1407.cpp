#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll f2(ll n){
    ll x = 2;
    ll sum = n;
    for(int i = 1;i<=50;i++){
        x = ll(1) << i;
        sum += (n / x) * (x >> 1);
    }
    return sum;
}

int main(int argc, char const *argv[]){
    ll a, b;
    cin >> a >> b;
    cout << f2(b) - f2(a-1);
    return 0;
}
