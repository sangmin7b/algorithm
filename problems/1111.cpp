#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

void solve(){
    int N;
    cin >> N;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    if(N == 1){
        cout << "A";
        return;
    }
    if(nums[0] == nums[1]){
        for(int num: nums){
            if(num != nums[0]){
                cout << "B";
                return;
            }
        }
        cout << nums[0];
        return;
    }
    if(N == 2){
        cout << "A";
        return;
    }

    pii p1 = {nums[0], nums[1]};
    pii p2 = {nums[1], nums[2]};
    
    bool is_impossible = false;
    int a = (p2.second - p1.second) / (p2.first - p1.first);
    int b = p1.second - a * p1.first;
    for(int i=0;i<N-1;i++){
        if(a*nums[i] + b != nums[i+1]){
            is_impossible = true;
        }
    } 
    if(is_impossible){
        cout << "B";
    }else{
        cout << a * nums[N-1] + b;
    }
    return;
}

int main(int argc, const char** argv) {
    solve();
    return 0;
}