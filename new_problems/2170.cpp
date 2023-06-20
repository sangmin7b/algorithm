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
    vector<pi> v; 
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int start = v[0].first;
    int end = v[0].second;
    int ans = end - start;
    for(int i = 1; i < N; i++){
        if(v[i].second < end)
            continue;
        ans += v[i].second - max(end, v[i].first);
        end = v[i].second;
    }
    cout << ans;
    return 0;
}     