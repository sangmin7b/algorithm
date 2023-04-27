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
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int m  = 0;
    int ans = accumulate(nums.begin(), nums.end(),0) + 1;
    for(int x: nums){
        if(m + 1 < x){
            ans = m + 1;
            break;
        }
        m += x;
    }
    cout << ans << "\n";
    return 0;
}