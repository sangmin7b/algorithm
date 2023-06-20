#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int max_n = 2000;
int N;
vi nums;
vi cnt(2000001, 0);

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    nums = vi(N, 0);
    for(int i=0;i<N;i++){
        int x; cin >> x;
        cnt[x]++;
    }   
    ll ans = N; 
    for(int i=2;i<=2000000;i++){
        ll m = 0;
        for(int j=i;j<=2000000;j+=i)
            m += cnt[j];
        if(1 < m)
            ans = max(ans, m * i);
    }
    cout << ans << "\n";
    return 0;
}     