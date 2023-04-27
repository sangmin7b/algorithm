#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll gcd(ll a, ll b){
    if(a > b){
        return gcd(b, a);
    }
    if(b % a == 0){
        return a;
    }
    return gcd(b % a, a);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

int solve(ll a, ll b){
    if(a > b){
        return solve(b, a);
    }
    if(a == b){
        return 1;
    }
    ll ans = 1;
    ll mul = lcm(a+1, b+1);
    ll diff = b - a;
    for(ll g=1;g*g<=diff;g++){
        if(diff % g != 0){
            continue;
        }
        ll n = g - a % g;
        ll m = lcm(a+n, b+n);
        if(m == mul){
            ans = min((ll)ans, n);
        }
        if(m < mul){
            mul = m;
            ans = n;
        }
    
        ll g2 = diff / g;
        n = g2 - a % g2;
        m = lcm(a+n, b+n);
        if(m == mul){
            ans = min((ll)ans, n);
        }
        if(m < mul){
            mul = m;
            ans = n;
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
    return 0;
}     