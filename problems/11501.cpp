#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;

void solve(){
    int N; cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    ll ans = 0;
    int max_p = 0;
    for(int i=N-1;i>=0;i--){
        max_p = max(max_p, nums[i]);
        ans += max_p - nums[i];
    }
    cout << ans << "\n";
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