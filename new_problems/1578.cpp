#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

/*
    4 4 4 4 4
    naive:
    가장 많이 남은 K개 국가부터 배정
    K 종류를 만들 수 없을 때까지 계속    
    
*/
ll N, K;
vi nums;

bool check(ll x){
    ll total = x * K;
    ll s = 0;
    for(int i=0;i<N;i++){
        s += min((ll)nums[i], x);
    }
    return total <= s;
}

int main(int argc, const char** argv) {
    cin >> N >> K;
    nums = vi(N);
    for(int &x: nums){
        cin >> x;
    }
    ll lo = 0, hi = 5e10;
    while(lo < hi){
        ll mid = (lo + hi + 1) / 2;
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo; 
    return 0;
}