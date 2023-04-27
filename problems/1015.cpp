#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>; 
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<pii> nums;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        nums.push_back({x,i});
    }
    stable_sort(nums.begin(), nums.end());
    vector<int> P(N,0);
    for(int i=0;i<N;i++){
        P[nums[i].second] = i; 
    }
    for(int p: P){
        cout << p << " ";
    }
    cout << "\n";
    return 0;
}