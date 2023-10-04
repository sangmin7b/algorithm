#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll dist(pi &a, pi &b){
    return (ll)(a.first - b.first) * (a.first - b.first) + (ll)(a.second - b.second) * (a.second - b.second);
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<pi> points(N);
    queue<int> q;
    vi visited(N);
    for(auto &p : points) cin >> p.first >> p.second;
    for(int i = 0; i < N; i++){
        q.push(i);
    }
    while(q.size() != 1){
        auto idx = q.front(); q.pop();
        if(visited[idx]) continue;
        ll d = 1e18;
        int target = 0;
        for(int i = 0; i < N; i++){
            if(!visited[i] && i != idx && dist(points[idx], points[i]) < d){
                d = dist(points[idx], points[i]);
                target = i;
            }
        }
        visited[target] = 1;
        q.push(idx);
    }
    cout << q.front() + 1;    
    return 0;
}     