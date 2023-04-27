#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int p = 1e9+7;

int gcd(int a, int b){
    if(a < b){
        return gcd(b, a);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);    
}

int inv(int x){
    int p2 = p-2;
    ll m = x;
    ll inverse  = 1;
    while(p2){
        if(p2 & 1){
            inverse *= m;
            inverse %= p;
        }
        m *= m;
        m %= p ;
        p2 >>= 1;
    }
    return inverse;
}

int main(int argc, const char** argv) {
    int M;
    cin >> M;
    vector<int> N(M,0);
    vector<int> S(M,0);
    for(int i=0;i<M;i++){
        cin >> N[i] >> S[i];
    }

    ll sum_S = 0;
    ll mult_N = 1;

    for(int i=0;i<M;i++){
        int g = gcd(mult_N, N[i]);
        mult_N *= N[i];
        mult_N %= p;
        mult_N *= inv(g);
        mult_N %= p;
    }

    for(int i=0;i<M;i++){
        sum_S += ((mult_N * S[i]) % p) * inv(N[i]) % p;
        sum_S %= p;
    }
    int ans = sum_S * inv(mult_N) % p;
    cout << ans;
    return 0;
}