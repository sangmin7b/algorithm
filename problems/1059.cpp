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
    int N; cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int K; cin >> K;
    int a = 0, b = K+1;
    for(int x: nums){
        if(x < K){
            a = x;
        }
        if(K < x){
            b = x;
            break;
        }
        if(x == K){
            cout << 0;
            return 0;
        }
    }
    // (K) * (K+1 ~ b -1)
    // (a+1 ~ K -1) * (K ~ b-1)
    cout << max((b - K - 1), 0) + max((K - a - 1), 0) * (b - K);
    return 0;
}     