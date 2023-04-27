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
    int N, C, M;
    cin >> N >> C;
    cin >> M;
    vvi box(N, vi(N, 0));
    vi cnt(N,0);
    vector<pair<int,pi>> v;

    for(int i=0;i<M;i++){
        int from, to, x;
        cin >> from >> to >> x;
        from--; to--;
        v.push_back({to,{from, x}});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(auto p: v){
        int from, to, x;
        to = p.first;
        from = p.second.first;
        x = p.second.second;
        int m = *max_element(cnt.begin() + from, cnt.begin() + to);
        int c = min(C - m, x);
        if(c > 0){
            ans += c;
            for(int i=from;i<to;i++){
                cnt[i] += c;
            }
        }
    }
    cout << ans;
    return 0;
}     