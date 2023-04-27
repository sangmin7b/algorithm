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
set<ll> s;
void check(ll x){
    vl r;
    for(ll d: s){
        if(x % d && (x+1) % d){
            r.push_back(d);
        }
    }
    for(ll d: r){
        s.erase(d);
    }
    return;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    nums = vl(N);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    if(nums.size() == 1){
        cout << nums[0]+1;
        return 0;
    }
    ll min_d = 1e12;
    
    for(int i=0;i<nums.size()-1;i++){
        ll d = nums[i+1] + 1 - nums[i];
        min_d = min(min_d, d);
    }
    for(ll i=1;i*i<=min_d;i++){
        if(min_d % i == 0){
            s.insert(i);
            s.insert(min_d/i);
        }
    }
    for(ll i=1;i*i<=min_d-1;i++){
        if((min_d - 1) % i == 0){
            s.insert(i);
            s.insert((min_d - 1)/i);
        }
    }
    for(int i=1;i<nums.size();i++){
        check(nums[i]);
    }    
    ll ans = 1;
    for(ll x: s){
        ans = max(ans, x);
    }
    cout << ans;
    return 0;
}