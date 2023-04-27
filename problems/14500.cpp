#include<bits/stdc++.h>
#include <vector>
using namespace std;
using matrix = vector<vector<int>>;
int N, M;
matrix visited;
matrix nums;
int search(int i, int j, int d){
    visited[i][j] = 1;
    if(d == 1){
        visited[i][j] = 0;
        return nums[i][j];
    }
    int res = 0;
    for(auto [di, dj]: {pair<int,int>{1,0}, {-1,0}, {0,1}, {0, -1}}){  
        int n_i = i + di, n_j = j + dj;
        if(0<= n_i && n_i < N && 0 <= n_j && n_j < M){
            if(visited[n_i][n_j]){
                continue;
            }
            res = max(res,search(n_i, n_j, d-1));
        }
    }
    visited[i][j] = 0;
    return res + nums[i][j];
}

int search2(int i, int j){
    int sum = 0;
    int cnt = 0;
    for(auto [di, dj]: {pair<int,int>{1,0}, {-1,0}, {0,1},{0,-1}}){  
        int n_i = i + di, n_j = j + dj;
        if(0<= n_i && n_i < N && 0 <= n_j && n_j < M){
            cnt++;
            sum += nums[n_i][n_j];
        }
    }
    if(cnt < 4){
        return nums[i][j] + sum;
    }
    int res = 0;
    for(auto [di, dj]: {pair<int,int>{1,0}, {-1,0}, {0,1},{0,-1}}){  
        int n_i = i + di, n_j = j + dj;
        if(0<= n_i && n_i < N && 0 <= n_j && n_j < M){
            res = max(res, sum - nums[n_i][n_j]);
        }
    }
    return nums[i][j] + res;
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    nums = matrix(N,vector<int>(M,0));
    visited = matrix(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> nums[i][j];
        } 
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int r = max(search(i, j, 4), search2(i,j));
            ans = max(r, ans);
        }
    }
    cout << ans;
    return 0;
}