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
    int N;
    cin >> N;
    vvi game_map(N, vi(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> game_map[i][j];
        }
    }
    vvi visited(N, vi(N, 0));
    queue<pi> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        int d = game_map[row][col];
        if(d == -1){
            break;
        }        
        int n_row = row + d;
        int n_col = col + d;
        if(n_row < N && !visited[n_row][col]){
            visited[n_row][col] = 1;
            q.push({n_row, col});
        }
        if(n_col < N && !visited[row][n_col]){
            visited[row][n_col] = 1;
            q.push({row, n_col});
        }        
    }
    if(visited[N-1][N-1]){
        cout << "HaruHaru";
    }else{
        cout << "Hing";
    }
    return 0;
}