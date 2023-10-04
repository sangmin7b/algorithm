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
    vector<pi> v(N);
    for(auto &x : v){
        int a, b; cin >> a >> b;
        if(b < a) x = {b, a};
        else x = {a , b};
    }
    sort(v.begin(), v.end());
    vector<pi> v2(v);
    auto cmp = [](pi &a, pi &b) -> bool{
        return (pi){a.second, a.first} < (pi){b.second, b.first};
    };
    sort(v2.begin(), v2.end(), cmp);
    int d; cin >> d;
    int idx = 0;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        while(idx < N && v2[idx].second <= v[i].first + d){
            if(v[i].first <= v2[idx].second && v[i].first <= v2[idx].first){
                cnt++;
            }
            idx++;
        }
        ans = max(ans, cnt);
        if(v[i].second <= v[i].first + d) cnt--;
    }
    cout << ans;
    return 0;
}     