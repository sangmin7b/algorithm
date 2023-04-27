#include<bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

vvi heights;
vvi visited;
int N;

void bfs (int i, int j, int h){
    queue<pii> q;
    visited[i][j] = 1;
    q.push({i, j});
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        for(pii dv: vector<pii>{pii {1,0}, {-1,0}, {0, 1}, {0, -1}}){
            pii next = {p.first + dv.first, p.second + dv.second};
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= N)
                continue;
            if(visited[next.first][next.second]  || heights[next.first][next.second] < h)
                continue;
            visited[next.first][next.second] = 1;
            q.push(next);
        }
    }
    return;
}

int search(int h){
    visited = vvi(N, vi(N, 0));
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] || heights[i][j] < h)
                continue;
            cnt++;
            bfs(i, j, h);
        }
    }
    return cnt;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    heights = vvi(N,vi(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> heights[i][j];
        }
    }
    int ans = 0;
    for(int h=0;h<=100;h++){
        ans = max(ans, search(h));
    }
    cout << ans;
    return 0;
}