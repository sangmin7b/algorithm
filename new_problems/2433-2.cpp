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
    int n, m, c; cin >> n >> m >> c;
    vi sample(n);
    for(int &x : sample) cin >> x;
    vi ans;
    multiset<int> s;
    for(int i = 0; i < m - 1; i++) s.insert(sample[i]);
    for(int i = 0; i < n - m + 1; i++){
        s.insert(sample[i+m-1]);
        if(*s.rbegin() - *s.begin() <= c) ans.push_back(i + 1);
        s.erase(s.find(sample[i]));
    }
    if(ans.size()){
        for(int x: ans) cout << x << "\n";
    }else{
        cout << "NONE";
    }
    return 0;
}     