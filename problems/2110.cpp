#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int N, C;
    cin >> N >> C;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    function <bool(int)> is_possible = [=](int x){
        int idx = 1;
        int cnt = 1;
        int prev = nums[0];
        while(idx < N){
            if(prev + x <= nums[idx]){
                prev = nums[idx];
                cnt++;
            }
            idx++;
        }
        return C <= cnt;
    };
    int ans = 0;
    int l = 1, r = nums[N-1] - nums[0];
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(is_possible(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    ans = l;
    cout << ans;
    return 0;
}