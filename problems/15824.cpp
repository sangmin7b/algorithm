#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N;
const int MOD = 1e9 + 7;
vl pow2(300001, 1);

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 0; i < 300000; i++){
        pow2[i + 1] = (2 * pow2[i]) % MOD;
    }
    cin >> N;
    vi nums(N);
    for(int &x : nums){
        cin >> x;
    }
    vi rank(nums);
    map<int, int> num_to_rank;
    sort(rank.begin(), rank.end());
    rank.resize(unique(rank.begin(), rank.end()) - rank.begin());
    for(int i = 0; i < rank.size(); i++){
        num_to_rank[rank[i]] = i;
    }
    vi cnt(N, 0);
    for(int i = 0; i < N; i++){
        cnt[num_to_rank[nums[i]]]++;
    }
    ll ans = 0;
    ll lcnt = 0;
    for(ll x : rank){
        ll icnt = cnt[num_to_rank[x]];
        ll rcnt = N - lcnt - icnt;
        ans += (pow2[lcnt] * (pow2[icnt] - 1) % MOD) * x % MOD;
        ans -= (pow2[rcnt] * (pow2[icnt] - 1) % MOD) * x % MOD;
        ans %= MOD;        
        ans += MOD;        
        ans %= MOD;        
        lcnt += icnt;
    }
    cout << ans;
    return 0;
}