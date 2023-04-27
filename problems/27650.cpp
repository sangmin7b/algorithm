#include<bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vi primes;
    vi is_prime(N+1,1);
    for(int i=2;i<=N;i++){
        if(!is_prime[i]){continue;}
        for(int j=2*i;j<=N;j+=i){
            is_prime[j] = 0;
        }
    }
    for(int i=2;i<=N;i++){
        if(is_prime[i]){
            primes.push_back(i);
        }        
    }
    int lo = 0, hi = primes.size()-1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        cout << "? " << primes[mid] << endl;
        int x; cin >> x;
        if(x){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    cout << "! " << primes[lo] << endl;
    return 0;
}     

