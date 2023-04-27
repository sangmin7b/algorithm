#include<bits/stdc++.h>
using namespace std;

vector<bitset<500>> visited;
int R, C;
bool dfs(int r, int c){
    visited[r][c] = 1;
    if(c == C - 1)
        return true;
    for(int i=-1;i<=1;i++){
        int next = r + i;
        if(next < 0 || next >= R || visited[next][c+1])
            continue;
        if(dfs(next,c+1))
            return true;
    }
    return false;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    visited = vector<bitset<500>>(R, bitset<500>(0));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char c; cin >> c;
            visited[i][j] = (c == 'x');
        }
    }
    int ans = 0;
    for(int i=0;i<R;i++){
        if(dfs(i, 0))
            ans++;
    }
    cout << ans;
    return 0;
}