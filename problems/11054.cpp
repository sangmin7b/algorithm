#include<bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> l_cnt(N,0);
    vector<int> r_cnt(N,0);
    
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    for(int i=1;i<N;i++){
        int cnt = 0;
        int m = 0;
        for(int j=i-1;j>=0;j--){
            if(l_cnt[j] >= cnt && nums[i] > nums[j]){
                m = nums[j];
                cnt = l_cnt[j] + 1;
            }
        }
        l_cnt[i] = cnt;
    }
    for(int i=N-2;i>=0;i--){
        int cnt = 0;
        int m = 0;
        for(int j=i+1;j<N;j++){
            if(r_cnt[j] >= cnt && nums[i] > nums[j]){
                m = nums[j];
                cnt = r_cnt[j] + 1;
            }
        }
        r_cnt[i] = cnt;
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        ans = max(ans, l_cnt[i] + r_cnt[i] + 1);
    }
    cout << ans;
    return 0;
}