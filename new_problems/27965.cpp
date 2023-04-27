#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
int len(int x){
    int ans = 0;
    while(x){
        ans++;
        x /= 10;
    }
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vl m(N+1,1);
    vi pow(len(N)+1, 1);
    for(int i=1;i<=len(N);i++){
        pow[i] = (ll)pow[i-1] * 10 % K; 
    }
    for(int i=N-1;0<i;i--){
        m[i] = m[i+1];
        int l = len(i+1);
        m[i] *= pow[l];
        m[i] %= K;
    }
    ll ans = 0;
    for(int i=1;i<=N;i++){
        ans += i * m[i] % K;
        ans %= K;
    }
    cout << ans;
    return 0;
}     