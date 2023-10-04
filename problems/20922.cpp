#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, K;
vi nums;

bool find(int L){
    vi cnt(100001, 0);
    int fail = 0;
    for(int i = 0; i < L; i++){
        cnt[nums[i]]++;
        if(cnt[nums[i]] == K + 1){
            fail++;
        }
    }
    if(!fail){
        return true;
    }
    for(int i = L; i < N; i++){
        cnt[nums[i]]++;
        cnt[nums[i-L]]--;
        if(nums[i] == nums[i-L]){
            continue;
        }
        if(cnt[nums[i]] == K + 1){
            fail++;
        }
        if(cnt[nums[i-L]] == K){
            fail--;
        }
        if(!fail){
            return true;
        }
    }
    return false;
}

int main(int argc, const char** argv) {
    cin >> N >> K; 
    nums = vi(N);
    for(int &x : nums){
        cin >> x;
    }
    int lo = 0, hi = N;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(find(mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo;
    return 0;
}     