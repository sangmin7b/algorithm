#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using dpstate = bitset<15>;
int N;
vvi adj;
int dp[1<<15][15][10];
int solve(dpstate s, int x, int p){
    if(10 <= p){
        return 1;
    }
    if(dp[s.to_ulong()][x][p]){
        return dp[s.to_ulong()][x][p];
    }
    int res = 1;
    for(int i=0;i<N;i++){
        int next_p = adj[x][i];
        if(next_p >= p && s[i] == 0){
            dpstate s2 = s;
            s2[i] = 1;
            res = max(res, solve(s2, i, next_p) + 1);
        }        
    }
    return dp[s.to_ulong()][x][p] = res;    
}

int main(int argc, const char** argv) {
    cin >> N;
    adj = vvi(N, vi(N));
    for(auto &v: adj){
        string s; cin >> s;
        for(int i=0;i<N;i++){
            v[i] = s[i] - '0';
        }
    }
    cout << solve(dpstate(1), 0, 0);
    return 0;
    // dp[2^15][x][p]
    // dp[state][x][p]
    // 지금까지 소유한 적 있는 사람들 s 
    // 지금 그림을 가지고 있는 사람이 x,현재가격이 p일때 그림을 소유한 적 있는 사람 수의 최댓값
    // 답은 dp[1][0][0]
}     