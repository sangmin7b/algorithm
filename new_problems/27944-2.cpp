#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vl nums;
int N;
unordered_set<ll>s;
void check(ll x){
    unordered_set<ll> s2;
    for(ll d: s){
        s2.insert(__gcd(x, d));
        s2.insert(__gcd(x+1, d));
    }
    s = s2;
    return;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    nums = vl(N);
    for(ll &x: nums){
        cin >> x;
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    s.insert(nums[0]);
    s.insert(nums[0]+1);
    for(int i=1;i<nums.size();i++){
        check(nums[i]);
    }
    ll ans = 0;
    for(ll x: s){
        ans = max(ans, x);
    }
    cout << ans;
    return 0;
}     