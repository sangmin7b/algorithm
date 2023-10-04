#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    for(int i = 0; i < N - 1; i++){
        int x; cin >> x;
    }
    vl psum(N);
    for(auto &x: psum) cin >> x;
    sort(psum.begin(), psum.end(), greater<ll>());
    for(int i = 0; i < N - 1; i++){
        psum[i + 1] += psum[i];
    }
    for(auto x: psum) cout << x << "\n";
    return 0;
}     