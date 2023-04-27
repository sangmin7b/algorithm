#include<bits/stdc++.h>
#define SZ 1000
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int ground[SZ][SZ];
int available[SZ][SZ];
int N, W;

bool is_inside(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool check(int k){
    vvi visited(N, vi(N,0));
    queue<pi> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(!is_inside(r+dr, c+dc) 
                    || k < available[r+dr][c+dc] 
                    || (available[r+dr][c+dc] == -1)
                    || visited[r+dr][c+dc]
                    || !ground[r+dr][c+dc]
                ){
                    continue;                    
                }            
                visited[r+dr][c+dc] = 1;
                q.push({r+dr, c+dc});
            }
        }
    }
    return visited[N-1][N-1];
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> W;
    queue<pi> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            available[i][j] = -1;
        }
    }
    available[N-1][N-1] = 0;
    for(int i=0;i<W;i++){
        int r, c; cin >> r >> c;
        r--; c--;
        q.push({r,c});
        available[r][c] = 0;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c; cin >> c;
            ground[i][j] = c - '0';
        }
    }
    while(!q.empty()){
        auto[r, c] = q.front();
        q.pop();
        for(int d=-1;d<=1;d+=2){
            if(is_inside(r+d, c) && available[r+d][c] == -1){
                available[r+d][c] = available[r][c] + 1;
                q.push({r+d, c});
            }
            if(is_inside(r,c+d) && available[r][c+d] == -1){
                available[r][c+d] = available[r][c] + 1;
                q.push({r,c+d}); 
            }
        }
    }
    int lo = 0, hi = 2 * N;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    if(lo == 2*N){
        cout << -1;
    }else{
        cout << lo;
    }
    return 0;
}     