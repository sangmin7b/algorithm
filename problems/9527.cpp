#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll g(ll x){
    x += 1;
    ll sum = 0;
    for(ll i = 1; i <= x; i *= 2){
        sum += (x / (i << 1)) * i + max((x % (i << 1) - i), 0LL);
    }
    return sum;
}

int main(int argc, char* const argv[]){
    ll a, b;
    cin >> a >> b;
    cout << g(b) - g(a - 1);
    return 0;
}