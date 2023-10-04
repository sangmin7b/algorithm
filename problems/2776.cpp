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
    set<int> s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        cout << s.count(x) << "\n";
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}     