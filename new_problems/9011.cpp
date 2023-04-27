#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void solve(){
    int n; cin >> n;
    vi nums(n);
    for(int &x: nums){
        cin >> x;
    }
    for(int i=0;i<n;i++){
        if(i < nums[i]){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    vi ans(n, 0);
    vi candidate(n, 0);
    iota(candidate.begin(), candidate.end(), 1);
    for(int i = n-1;0 <= i;i--){
        ans[i] = candidate[nums[i]];
        candidate.erase(candidate.begin() + nums[i]);
    }
    for(int x: ans){
        cout << x << " ";
    }
    cout << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}