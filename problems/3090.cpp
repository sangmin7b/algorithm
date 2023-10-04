#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll N, T;
vl nums(N);
vl ans;    

bool check(ll mid){
    ll cnt = 0;
    ans = nums;
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    for(int i = 0; i < N; i++){
        pq.push({nums[i], i});            
    }  
    while(!pq.empty()){
        auto [v, idx] = pq.top(); pq.pop();
        if(v > ans[idx]) continue;
        if(0 < idx && ans[idx] + mid < ans[idx - 1]){
            cnt += ans[idx - 1] - ans[idx] - mid;  
            ans[idx - 1] = ans[idx] + mid;
            pq.push({ans[idx - 1], idx - 1});
        }            
        if(idx < N - 1 && ans[idx] + mid < ans[idx + 1]){
            cnt += ans[idx + 1] - ans[idx] - mid;  
            ans[idx + 1] = ans[idx] + mid;
            pq.push({ans[idx + 1], idx + 1});
        }          
    }  
    return cnt <= T;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> T;
    nums = vl(N);
    for(auto &x : nums) cin >> x;
    ll lo = 0, hi = 1e9;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    check(lo);
    for(ll x: ans) cout << x << " ";
    return 0;
}     