#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9+7;
const int R = 4000000;

int fac[R+1];
int inv(int x){
    int P2 = P-2;
    ll inverse = 1;
    ll m = x;
    while(P2){
        if(P2 % 2){
            inverse *= m;
            inverse %= P;
        }
        m *= m;
        m %= P;
        P2 /= 2;
    }
    return inverse;
}



int solve(int N, int K){
    // N!/K!(N-K)!
    return ((ll)fac[N] * inv(fac[K]) % P ) * inv(fac[(N-K)]) % P; 
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2;i<=R;i++){
        fac[i] = (ll)fac[i-1] * i % P;
    }
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int N, K;
        cin >> N >> K;
        cout << solve(N,K)<<"\n";
    }
    return 0;
}