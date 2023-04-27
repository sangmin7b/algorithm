#include<bits/stdc++.h>
using namespace std;
const int max_n = 4000000;
vector<int> primes;
vector<bool> is_prime(max_n,1);

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int n=2;n<max_n;n++){
        if(!is_prime[n])
            continue;
        for(int k=2*n;k<max_n;k+=n){
            is_prime[k] = 0;
        }
    }
    for(int n=2;n<max_n;n++){
        if(is_prime[n]){
            primes.push_back(n);
        }
    }
    int N;
    cin >> N;
    int ans = 0;
    int l = 0;
    int r = 1;
    int x = primes[l];
    while(r <= primes.size() && l < r){
        if(x == N){
            ans++;
            x += primes[r];
            r++;
        }else if(x < N){
            x += primes[r];
            r++;
        }else{
            x -= primes[l];
            l++;
        }
    }

    cout << ans;
    return 0;
}     