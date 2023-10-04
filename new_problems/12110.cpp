#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int board[20][20];
int N;

pi operator +(pi &a, const pi &b){
    return {a.first + b.first, a.second + b.second};
};

pi operator -(pi &a, const pi &b){
    return {a.first - b.first, a.second - b.second};
};

void move(int m){
    pi d[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    pi diff[4] = {{0, 1}, {1, 0}, {0, 1}, {1, 0}};
    pi start[4] = {{0, 0}, {0, 0}, {N - 1, 0}, {0, N - 1}};
    pi end[4] = {{N, 0}, {0, N}, {-1, 0}, {0, -1}};

    auto shift = [&](){
        for(pi p = start[m] + d[m]; p != end[m]; p = p + d[m]){
            auto [i, j] = p;
            if(board[i][j] == 0) continue;
            pi k = p;
            while(k != start[m] && board[(k - d[m]).first][(k - d[m]).second] == 0){
                k = k - d[m];
            }
            int t = board[i][j];
            board[i][j] = 0;
            board[k.first][k.second] = t;
        }
    };

    auto merge = [&](){
        for(pi p = start[m]; p != (end[m] - d[m]); p = p + d[m]){
            auto [i, j] = p;
            if(board[i][j] == 0) continue;
            pi k = p + d[m];
            if(board[k.first][k.second] == board[i][j]){
                board[i][j] += board[k.first][k.second];
                board[k.first][k.second] = 0;
            }
        }
    };

    for(int ii = 0; ii < N; ii++){
        shift();
        merge();
        shift();
        start[m] = start[m] + diff[m];
        end[m] = end[m] + diff[m];
    }
}

int dfs(int step, int m){
    if(step == 5){
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans = max(ans, board[i][j]);
            }
        }
        return ans;
    }
    int prev_board[20][20];
    int ans = 0;
    memcpy(prev_board, board, 20 * 20 * sizeof(int));
    for(int i = 0; i < 4; i++){
        memcpy(board, prev_board, 20 * 20 * sizeof(int));
        move(i);
        ans = max(ans, dfs(step + 1, i));
    }
    memcpy(prev_board, board, 20 * 20 * sizeof(int));
    return ans;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    cout << dfs(0, -1);
    return 0;
}     
