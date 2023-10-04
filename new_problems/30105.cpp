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
    vi nums(N);
    for(auto &x : nums) cin >> x;
    vector<int> ans;
    for(int i = 1; i <= N / 2; i++){
        ans.push_back(nums[i] - nums[0]);
    }
    for(int i = 1; i < N; i++){
        set<int> s;
        for(int j = max(0, i - N / 2 - 1); j < min(N, i + N / 2 + 1); j++){
            s.insert(abs(nums[i] - nums[j]));
        }
        vector<int> tmp;
        for(int x : ans){
            if(s.find(x) != s.end()){
                tmp.push_back(x);
            }
        }
        ans = tmp;
    }
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    return 0;
}     