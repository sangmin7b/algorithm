#include<bits/stdc++.h>
using namespace std;
#define INF 1E9
vector<vector<char>>board;

int check(int r, int c){
    int start_with_white = 0;
    int start_with_black = 0;
    for(int i=r;i<r+8;i++){
        for(int j=c;j<c+8;j++){
            int s = i + j;
            if(s % 2 == 0){
                if(board[i][j] == 'B'){
                    start_with_white++;
                }else{
                    start_with_black++;
                }
            }else{
                if(board[i][j] == 'W'){
                    start_with_white++;
                }else{
                    start_with_black++;
                }
            }
        }
    }
    return min(start_with_white, start_with_black);
}

int main(int argc, const char** argv){
    int N, M;
    cin >> N >> M;
    board = vector<vector<char>>(N, vector<char>(M,0));
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            board[i][j] = s[j];
        }
    }
    int ans = INF;
    for(int i=0;i+8<=N;i++){
        for(int j=0;j+8<=M;j++){
            ans = min(ans, check(i,j));
        }
    }
    cout << ans;

    return 0;
}