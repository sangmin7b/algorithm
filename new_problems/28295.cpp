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
    int N = 10;
    int dir = 0;
    for(int i = 0; i < N; i++){
        int t; cin >> t;
        dir += t;
        dir %= 4;
    }
    string ans = "NESW";
    cout << ans[dir];
    return 0;
}     