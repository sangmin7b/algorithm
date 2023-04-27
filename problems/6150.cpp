#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 98765431;
int N, T;
int m_pow(ll x, int t){
    ll ans = 1;
    while(t){
        if(t & 1){
            ans *= x;
            ans %= mod;
        }
        t /= 2;
        x *= x;
        x %= mod;
    }
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> T;
    ll sum = 0;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
        sum += nums[i];
    }
    sum %= mod;
    ll ans = sum * (1LL - m_pow(1-N, T)) % mod;
    if(T == 0){
        ans = 0;
    }
    if(T % 2 == 0){
        ans = mod - ans % mod;
    }
    ans *= m_pow(N, mod-2);
    ans %= mod;
    for(int i = 0; i < N; i++){
        if(T % 2 == 1){
            cout << (ans + mod - nums[i] % mod) % mod << "\n"; 
        }else{
            cout << (ans + nums[i]) % mod << "\n";
        }
    }
    return 0;
}     