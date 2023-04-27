#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll gcd(ll a, ll b){
    if(a < b){
        return gcd(b ,a);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int adj[10][10][2];
int N;
ll ans[10];

void dfs(int now, int par){
    for(int next=0;next<N;next++){
        if(next == par || !adj[now][next][0]){
            continue;
        }
        ans[next] = ans[now] / adj[now][next][0] * adj[now][next][1];
        dfs(next, now);
    }
    return;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    ll m = 1;
    for(int i=0;i<N-1;i++){
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        adj[a][b][0] = p;
        adj[a][b][1] = q;
        adj[b][a][0] = q;
        adj[b][a][1] = p;
        m *= p * q;
    }
    ans[0] = m;
    dfs(0, -1);
    ll g = m;
    for(int i=0;i<N;i++){
        g = gcd(g, ans[i]);
    }
    for(int i=0;i<N;i++){
        cout << ans[i] / g << " ";
    }    
    return 0;
}     