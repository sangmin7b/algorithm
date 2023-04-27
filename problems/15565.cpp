#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;


int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    int i=0, j=1;
    int cnt = nums[i] == 1 ? 1 : 0;
    int ans = -1;
    while(j < N){
        while(i < j && cnt >= K){
            if(nums[i] == 1){
                cnt--;            
                while(nums[i+1] != 1){
                    i++;
                }
            }
            i++;
        }
        while(cnt < K && j < N){
            if(nums[j] == 1)
                cnt++;
            j++;
        }
        if(cnt >= K){
            if(ans == -1){
                ans = j - i;
            }else{
                ans = min(ans, j - i);
            }
        }
    }
    while(i < j && cnt >= K){
        if(nums[i] == 1)
            cnt--;            
        i++;
    }
    if(cnt >= K){
        if(ans == -1){
            ans = j - i;
        }else{
            ans = min(ans, j - i);
        }
    }
    cout << ans;
    return 0;
}