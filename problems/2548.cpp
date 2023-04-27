#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << nums[(N-1)/2];
    return 0;
}