#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, X;
    cin >> N;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    cin >> X;
    sort(nums.begin(), nums.end());
    int ans = 0;
    int l = 0;
    int r = N - 1;
    while(l < r){
        int x = nums[l] + nums[r];
        if(x == X){
            ans++;
            l++;
        }else if(x < X){
            l++;
        }else{
            r--;
        }
    }
    cout << ans;
    return 0;
}     