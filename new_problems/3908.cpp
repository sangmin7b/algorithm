#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int N = 1200;
const int K = 14;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vi is_prime(N+1,1);
    vi primes;
    for(int i=2;i<N;i++){
        if(!is_prime[i]){ 
            continue;
        }
        for(int j=2*i;j<N;j+=i){
            is_prime[j] = 0;
        }
    }
    for(int i=2;i<N;i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
    vvi dp(N+1, vi(K+1, 0));
    dp[0][0] = 1;
    for(int p: primes){
        for(int x=N;0<=x;x--){
            if(x < p){
                break;
            }
            for(int j=1;j<=K;j++){
                dp[x][j] += dp[x-p][j-1];                
            }
        }
    }    
    int T; cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        cout << dp[n][k] << "\n";
    }
    return 0;
}