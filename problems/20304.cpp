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
    int N, M;
    cin >> N >> M;
    int K = 0;
    while((1<<K) <= N){
        K++;
    }
    vi nums(M,0);
    vi dist(N+1, K);
    queue<int> q;
    for(int i=0;i<M;i++){
        int x; cin >> x;
        dist[x] = 0;
        q.push(x);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<K;i++){
            int next = x ^ (1 << i);
            if(next <= N && dist[x] + 1 < dist[next]){
                dist[next] = dist[x] + 1;
                q.push(next);
            }
        }
    }
    int ans = *max_element(dist.begin(), dist.end());
    cout << ans << "\n";
    return 0;
}     