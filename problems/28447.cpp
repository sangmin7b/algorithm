#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, K;
vvi score;
vi selected;

int solve(int idx, int cnt){
    if(idx == N && cnt != K) return -1e9;
    int ans = 0;
    if(idx == N && cnt == K){
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                if(selected[i] && selected[j]) ans += score[i][j];
            }   
        }
        return ans;
    }
    selected[idx] = 1;
    ans = solve(idx + 1, cnt + 1);
    selected[idx] = 0;
    ans = max(ans,solve(idx + 1, cnt));
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    score = vvi(N, vi(N, 0));
    for(auto &v : score){
        for(auto &x : v) cin >> x;
    }
    selected = vi(N, 0);
    int ans = solve(0, 0);
    cout << ans;
    return 0;
}     