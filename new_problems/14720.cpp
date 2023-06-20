#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    int N; cin >> N;
    vector<int> nums(N);
    for(int &x : nums){
        cin >> x;
    }
    int state = 0;
    int ans = 0;
    for(int x : nums){
        if(x == state){
            ans++;
            state++;
            state %= 3;
        }
    }
    cout << ans;
    return 0;
}
