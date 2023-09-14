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
    int N; cin >> N;
    vl nums(N);
    for(auto &x : nums) cin >> x;
    if(N == 1){
        cout << 0;
        return 0;
    }
    sort(nums.begin(), nums.end());
    auto prev_max = nums[N - 1];
    auto max_v = prev_max;
    priority_queue<ll, vl, greater<ll>> pq;
    for(int i = 0; i < N; i++){
        pq.push(nums[i]);
    }
    ll ans = max_v - pq.top();    
    while(pq.top() < prev_max){
        ll x = pq.top(); pq.pop();
        max_v = max(max_v, 2 * x);
        pq.push(2 * x);
        ans = min(ans, max_v - pq.top());
    }
    cout << ans;
    return 0;
}     