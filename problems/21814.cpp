#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll N;
    cin >> N;
    vi nums(N+1,0);
    vvi pos(N+1, vi());
    ll ans = N * (N - 1) / 2;
    for(int i = 1; i <= N; i++){
        cin >> nums[i];
        pos[nums[i]].push_back(i);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < pos[i].size(); j++){
            ans -= (N - pos[i][j] + 1);
        }
        for(int j = pos[i].size() - 2; 0 <= j; j--){
            ans -= pos[i][j];
        }
        ans += (ll) pos[i].size() * (pos[i].size() - 1) / 2;
    }
    cout << ans;    
    return 0;
}     