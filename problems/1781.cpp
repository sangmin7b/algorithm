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
    int N;
    cin >> N;
    vector<pi> nums(N);
    for(int i=0;i<N;i++){
        cin >> nums[i].second >> nums[i].first;
    }
    set<int, greater<int>> s;
    for(int i=1;i<=N;i++){
        s.insert(i);
    }
    sort(nums.begin(), nums.end(), greater<pi>());
    int ans = 0;
    for(auto p: nums){
        auto it = s.lower_bound(p.second);
        if(it == s.end()){
            continue;
        }
        s.erase(it);
        ans += p.first;
    }
    cout << ans;
    return 0;
}     