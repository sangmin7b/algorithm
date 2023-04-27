#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x = 1;
    ll prev = 0;
    for(int i=1;i<100;i++){
        x = lcm(x, i);
        if(x > prev + 10000){
            cout << i << " " << x << "\n";
        }
    }    
    return 0;
}     