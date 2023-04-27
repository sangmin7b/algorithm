#include<bits/stdc++.h>
#include <vector>
using namespace std;
using pic = pair<int,char>;
using pii = pair<int,int>;

int N;
vector<vector<int>> board;
queue<pii> next_pair;
enum{
    EMPTY, SNAKE, APPLE 
};

bool is_inside(pii p){
    return p.first >=0 && p.second >= 0 && p.first < N && p.second < N;
}

bool is_ok(pii p){
    return is_inside(p) && board[p.first][p.second] != SNAKE;
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int K;
    cin >> N >> K;

    board = vector<vector<int>>(N,vector<int>(N,EMPTY));
    for(int i=0;i<K;i++){
        int r,c; cin >> r >> c;
        r--; c--;
        board[r][c] = APPLE;
    }    
    int L;
    cin >> L;
    queue<pic> q;
    for(int i=0;i<L;i++){
        int t; char C;
        cin >> t >> C; 
        q.push({t,C});
    }
    int T = 0;
    board[0][0] = SNAKE;
    pii dir = {0,1};
    pii head = {0,0};
    pii tail = {0,0};
    while(1){
        T++;
        pii next_head = {head.first + dir.first, head.second + dir.second};
        next_pair.push(next_head);
        head = next_head;
        if(!is_ok(head)){
            break;
        }
        if(board[head.first][head.second] != APPLE){
            board[tail.first][tail.second] = EMPTY;
            tail = next_pair.front();
            next_pair.pop();
        }
        board[head.first][head.second] = SNAKE;
        pic cmd = q.front();
        if(cmd.first == T){
            switch (cmd.second){
                case 'L':
                    dir = {-dir.second, dir.first};
                    break;            
                case 'D':
                    dir = {dir.second, -dir.first};
                    break;
            }
            q.pop();
        }
    }
    cout << T;
    return 0;
}