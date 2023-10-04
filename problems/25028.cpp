#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int MOD = 1e9 + 7;

ll pow_n(ll x, int n){
    ll res = 1;
    while(n){
        if(n & 1)
            res *= x;
        res %= MOD;
        x *= 2;
        n = n >> 1;
    }
    return res;
}

ll solve(ll N){
    vi nums = {1, 2, 2};
    if(N <= 3){
        return nums[N - 1];
    }
    int cnt = 5;
    int i = 3;
    while(cnt < N){
        for(int j = 0; j < nums[i - 1]; j++){
            nums.push_back(i);        
            cnt += i;
            if(N <= cnt)
                break;
        }
        i++;
    }
    return nums.size();    
}

int main(int argc, const char** argv) {
    ll N; cin >> N;
    cout << solve(N);
    return 0;
}     