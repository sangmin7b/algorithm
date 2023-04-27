#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    vi nums(N,0);
    unordered_map<int, int> s;
    int zero_cnt = 0;
    for(int i=0;i<N;i++){
        cin >> nums[i];
        if(s.find(nums[i]) == s.end()){
            s[nums[i]] = 1;
        }else{
            s[nums[i]] = 2;
        }
        if(nums[i] == 0){
            zero_cnt++;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(nums[i] == 0 && nums[j] == 0){
                continue;
            }
            if(nums[i] != 0 && nums[j] != 0){
                s.erase(nums[i] + nums[j]);
                continue;
            }
            auto it = s.find(nums[i] + nums[j]);
            if(it != s.end() && it->second == 2){
                s.erase(it);
            }
        }
    }
    int cnt = 0;
    for(int x: nums){
        if(s.find(x) == s.end()){
            cnt++;
        }else if(x == 0 && 2 < zero_cnt){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}     