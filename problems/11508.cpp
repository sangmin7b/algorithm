#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<int> nums(N);
    for(int &x : nums){
        cin >> x;
    }
    sort(nums.begin(), nums.end(), greater<int>());
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(i % 3 != 2){
            ans += nums[i];
        }
    }
    cout << ans;
    return 0;
}
