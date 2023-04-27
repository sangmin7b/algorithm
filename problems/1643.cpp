#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<int>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll gcd(ll a, ll b){
    if(a < b){
        swap(a, b);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int len(ll x){
    int i = 0;
    while(x){
        i++;
        x /= 10;
    }
    return i;
}

void solve(int n){
    int z = 0;
    ll a = n, b = 1;
    for(int i=2;i<=n;i++){
        a = a * i + b * n;
        b *= i;
        if(a > b){
            z += a / b;
            a %= b;
        }
        if(a == 0){
            continue;
        }
        ll g = gcd(a, b);
        a /= g;
        b /= g;
    }
    if(a == b){
        z++;
        cout << z << "\n";
        return;
    }   
    if(a == 0){
        cout << z << "\n";
        return;
    }   

    for(int i=0;i<len(z);i++){
        cout << " ";
    }
    cout << " " << a << "\n";
    cout << z << " ";
    for(int i=0;i<len(b);i++){
        cout << "-";
    }
    cout << "\n";
    for(int i=0;i<len(z);i++){
        cout << " ";
    }
    cout << " " << b << "\n";
    return;
}

int main(int argc, const char** argv) {
    while(true){
        int n;
        cin >> n;
        if(cin.eof()){
            break;
        }
        solve(n);
    }
    return 0;
}