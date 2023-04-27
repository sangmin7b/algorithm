#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vi nums(N+2,0);
    for(int i=0;i<N;i++){
        cin >> nums[i+1];
    }
    nums[0] = nums[1];
    nums[N+1] = nums[N];
    int lo = 0, hi = 1e9;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        int cnt = 0;
        for(int i=1;i<=N;i++){
            if(mid < abs(nums[i-1] - nums[i]) || mid < abs(nums[i+1]-nums[i])){
                cnt++;
            }
        }
        if(K < cnt){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    cout << lo << "\n";
    return 0;
}     