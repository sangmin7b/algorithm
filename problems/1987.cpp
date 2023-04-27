#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<int> nums;

pair<pii,int> solve(int l, int r){
    if(r - l == 1){
        
    }
    if(r - l == 2){
        
    }



}   

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    nums = vector<int>(N+1);
    for(int i=0;i<N;i++){
        int r, c;
        cin >> r >> c;
        nums[i] = r;
        if(i==N-1){
            nums[i+1] = c;
        }
    }
    int ans = 0;
    cout << ans;
    return 0;
}