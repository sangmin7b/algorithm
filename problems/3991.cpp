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
    int h, w, c;
    cin >> h >> w >> c;
    vi nums(c,0);
    for(int i=0;i<c;i++){
        cin >> nums[i];
    }
    vvi board(h, vi(w,0));
    int color = 0;
    for(int i=0;i<h*w;i++){        
        if(nums[color] == 0){
            color++;
        }
        int row = i / w;
        int col = i % w;
        if(row % 2 == 1){  
            col = w - 1 - col;
        }
        board[row][col] = color + 1;
        nums[color]--;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}