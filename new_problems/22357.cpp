#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vi primes;
    vi is_prime(20000, 1);
    for(int i = 2; i <= 20000; i++){
        if(!is_prime[i]){
            continue;
        }
        primes.push_back(i);
        for(int j = 2*i; j <= 20000; j+=i){
            is_prime[j] = 0;
        }
    }
    int d = 0;
    while(primes[d] < 2000){
        d++;
    }
    set<int> s(primes.begin(), primes.end());
    int K, N; cin >> K >> N;
    vvi ans(K, vi(N, 0));
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            cout << 1 + j * primes[d + i] << " ";
        }
        cout << "\n";
    }
    return 0;
}     