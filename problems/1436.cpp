#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

bool ok(int x){
    int cnt = 0;
    while(x){
        if(x % 10 == 6){
            if(++cnt >= 3){
                return true;
            }
        }else{
            cnt = 0;
        }
        x /= 10;
    }
    return false;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    set<int> nums;
    int i = 666;
    while(nums.size()<100000){
        if(ok(i)){
            nums.insert(i);
        }
        i++;
    }
    vi ans(nums.begin(), nums.end());
    sort(ans.begin(), ans.end());
    cout << ans[N-1];    
    return 0;
}