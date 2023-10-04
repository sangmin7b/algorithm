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
    ll N, K;
    cin >> N >> K;
    vl nums(N);
    for(ll &x : nums){
        cin >> x;
    }

    // S N
    vl nums2(nums);
    for(int i = 0; i < N; i++){
        nums2[i] -= i * K;
    }
    ll ans = -1e9;
    ll right = nums2.back();
    for(int i = N-2; 0<=i; i--){
        ans = max(ans, right - nums2[i]);
        right = max(right, nums2[i]);
    }

    // N S
    for(int i = 0; i < N; i++){
        nums[i] += i * K;
    }
    ll left = nums.front();
    for(int i = 1; i < N; i++){
        ans = max(ans, left - nums[i]);
        left = max(left, nums[i]);
    }
    cout << ans;

    return 0;
}     