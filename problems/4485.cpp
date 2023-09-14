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
    int t = 1;
    while(1){
        int N; cin >> N;
        if(N == 0)  break;
        vvi board(N, vi(N, 0));
        for(auto &v : board){
            for(auto &x : v) cin >> x;
        }
        vvi dist(N, vi(N, 1e9));
        dist[0][0] = board[0][0];
        priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
        pq.push({board[0][0], {0, 0}});
        while(!pq.empty()){
            auto [v, p] = pq.top(); pq.pop();
            if(v > dist[p.first][p.second]) continue;
            for(int dr = -1; dr <= 1; dr += 2){
                if(p.first + dr < N  && 0 <= p.first + dr && dist[p.first + dr][p.second] > v + board[p.first + dr][p.second]){
                    dist[p.first + dr][p.second] = v + board[p.first + dr][p.second];
                    pq.push({dist[p.first + dr][p.second], {p.first + dr, p.second}});
                }
            }
            for(int dc = -1; dc <= 1; dc += 2){
                if(p.second + dc < N && 0 <= p.second + dc && dist[p.first][p.second + dc] > v + board[p.first][p.second + dc]){
                    dist[p.first][p.second + dc] = v + board[p.first][p.second + dc];
                    pq.push({dist[p.first][p.second + dc], {p.first, p.second + dc}});
                }
            }
        }
        cout << "Problem " << t++ << ": " << dist[N-1][N-1] << "\n";
    }
    return 0;
}     