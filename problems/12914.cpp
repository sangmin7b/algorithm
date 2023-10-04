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
    int N, d; cin >> N >> d;
    set<int> s;
    set<int, greater<int>> s2;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        while((s2.lower_bound(x) != s2.end() && *s2.lower_bound(x) > x - d) || (s.lower_bound(x) != s.end() && *s.lower_bound(x) < x + d)){
            if(s.lower_bound(x) != s.end() && *s.lower_bound(x) < x + d)
                x = *s.lower_bound(x) + d;
            else
                x = *s2.lower_bound(x) + d;
        }
        cout << x << " ";
        s.insert(x);
        s2.insert(x);
    }
    return 0;
}     