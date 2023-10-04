#include<bits/stdc++.h>
#include <functional>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, M;
vi height;
vi cnt;
vvi adj;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    height = vi(N,0);
    cnt = vi(N, 1);
    adj = vvi(N);
    vector<pi> v;
    for(int i = 0; i < N; i++){
        cin >> height[i];
        v.push_back({height[i], i});
    }
    sort(v.begin(), v.end(), greater<pi>());
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        if(height[a] < height[b]){
            adj[b].push_back(a);
        }else{
            adj[a].push_back(b);
        }
    }
    for(auto p: v){
        int x = p.second;
        for(int next: adj[x]){
            cnt[next] = max(cnt[next], cnt[x] + 1);
        }
    }
    for(int x: cnt){
        cout << x << "\n";
    }
    return 0;
}     