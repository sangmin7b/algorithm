#include <algorithm>
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
    for(int &x : nums){
        cin >> x;
    }
    int sum = 0;
    int ans = *max_element(nums.begin(), nums.end());
    for(int x: nums){
        sum += x;
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    cout << ans << "\n";
    return 0;
}     