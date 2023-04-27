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
    int N, L;
    cin >> N >> L;
    vector<pi> nums(N);
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        nums[i] = {x, y};
    }
    sort(nums.begin(), nums.end());
    int end = 0;
    int cnt = 0;
    for(pi p: nums){
        if(p.second > end){
            int start = max(end, p.first);
            int n = (p.second - start + L - 1) / L;
            cnt += n;
            end = start + n * L;
        }
    }
    cout << cnt << "\n";
    return 0;
}     