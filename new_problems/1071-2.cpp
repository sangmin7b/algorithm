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
    sort(nums.begin(), nums.end());
    for(int i = 0; i < N - 1; i++){
        if(nums[i] + 1 == nums[i+1]){
            int idx = -1;
            for(int j = i + 2; j < N; j++){
                if(nums[j] != nums[i+1] ){
                    idx = j;
                    break;
                }
            }            
            if(idx == -1){
                int k = i;
                while(0 < k && nums[k - 1] == nums[k]){
                    k--;
                }
                swap(nums[k], nums[i+1]);
            }else{
                swap(nums[i+1], nums[idx]);
            }
        }
    }
    for(int x: nums){
        cout << x << " ";
    }
    return 0;
}     