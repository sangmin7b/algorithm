#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N;
vvi board;
vvi psum;
enum DIR{
    UP, 
    DOWN, 
    LEFT, 
    RIGHT
};
char dirs[4] = {'U', 'D', 'L', 'R'};

int sum(pi s, pi e){
    if(s.first < 1 || N < s.second || e.first < 1 || N < e.second){
        return 0;
    }
    return psum[e.first][e.second] - psum[e.first][s.second-1] - psum[s.first-1][e.second] + psum[s.first-1][s.second-1];
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    board = vvi(N+2, vi(N+2, 0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> board[i][j];
        }
    }
    psum = vvi(N+2, vi(N+2, 0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + board[i][j];
        }
    }
    pi s, e;
    s = {N / 2, N / 2};
    e = {N / 2 + 1, N / 2 + 1};
    vi ans;
    int score = sum(s, e);
    while(1){
        int max_diff = 0;
        int dir = UP;
        vector<pair<pi, pi>> next = {{{s.first-1, s.second}, e}, 
            {s, {e.first+1, e.second}}, 
            {{s.first, s.second-1}, e},
            {s, {e.first,e.second+1}}};
        for(int i=0;i<4;i++){
            int next_score = sum(next[i].first, next[i].second); 
            if(max_diff < next_score - score){
                max_diff = next_score - score;
                s = next[i].first;
                e = next[i].second;
                dir = i;
            }
        }
        if(max_diff <= 0){
            break;
        }
        score += max_diff;
        ans.push_back(dir);   
    }
    cout << score << "\n";
    for(int d: ans){
        cout << dirs[d];
    }
    return 0;
}     