#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N;
multiset<int> nums;
vi ans;
bool solve(){
    if(nums.empty()){
        return true;
    }
    vi nums_copy(nums.begin(), nums.end());
    for(int x : nums_copy){
        if(ans.empty() || (ans.back() + 1 != x)){
            ans.push_back(x);
            nums.erase(nums.find(x));
            if(solve()){
                return true;
            }
            nums.insert(x);
            ans.pop_back();
        }
    }
    return false;
}   

int main(int argc, const char** argv) {
    cin >> N;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        nums.insert(x);
    }
    solve();
    for(int x: ans){
        cout << x << " ";
    }
    return 0;
}     