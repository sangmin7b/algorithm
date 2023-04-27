#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int solve(vi& v){
    int sum0 = 0;
    for(int i=1;i<v.size();i++){
        sum0 += v[i];
    }
    int max_score = INT32_MIN;
    int prev = -v.back();
    for(int i=v.size()-2;i>0;i--){
        int score = prev + 2 * v[i+1] - v[i];
        max_score = max(max_score, score);
        prev = score;
    }
    return sum0 + max_score;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vi nums(N,0);
    vi reversed(N, 0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
        reversed[N-1-i] = nums[i];
    }
    int sum = 0;
    int max_v = 0;
    for(int i=1;i<N-1;i++){
        max_v = max(max_v, nums[i]);
        sum += nums[i];
    }
    int case0 = sum + max_v;
    int case1 = solve(nums);
    int case2 = solve(reversed);
    
    int ans = max(case0, max(case1, case2));
    cout << ans;
    return 0;
}