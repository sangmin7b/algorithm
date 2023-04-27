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
    int h = 1;
    ll ans = 0;
    for(int x: nums){
        if(x < h){
            continue;
        }
        ans += x - h;
        h++;
    }
    cout << ans;
    return 0;
}     