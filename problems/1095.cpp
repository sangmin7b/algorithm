#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vi is_prime(1e5, 1);
vi primes;

int prime_count(int x, int p){
    int cnt = 0;
    while(x){
        cnt += x / p;
        x /= p;
    }
    return cnt;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 2; i < 1e5; i++){
        if(!is_prime[i]) continue;
        for(int j = 2 * i; j < 1e5; j += i){
            is_prime[j] = 0;
        }
    }
    for(int i = 2; i < 1e5; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    int S, F, M;
    cin >> S >> F >> M;
    vi nums(M + 1);
    iota(nums.begin(), nums.end(), 0);
    for(int p: primes){
        int c = prime_count(S + F, p) - prime_count(F, p) - prime_count(S, p);
        while(c--){
            for(int i = p; i <= M; i+=p){
                if(nums[i] && nums[i] % p == 0) nums[i] /= p;
            }
        }
    }
    int ans = M;
    for(int i = M; 0 < i; i--){
        if(nums[i] == 1){
            ans = i; 
            break;
        }
    }
    cout << ans;    
    return 0;
}     