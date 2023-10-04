#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using matrix = vvi;

const int MOD = 1e9 + 7;

matrix mmult(const matrix &A, const matrix &B){
    matrix C(A.size(), vector<int>(B[0].size(), 0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B[0].size();j++){
            for(int k=0;k<B.size();k++){
                C[i][j] += ((ll)A[i][k] * B[k][j] ) % MOD;
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

// 정보과학관, 전산관, 미래관, 신양관, 한경직기념관, 진리관, 학생회관, 형남공학관
int main(int argc, const char** argv) {
    vvi adj(8, vi(8, 0));
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    
    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;
    
    adj[2][3] = adj[3][2] = 1;
    adj[2][4] = adj[4][2] = 1;
    
    adj[3][4] = adj[4][3] = 1;
    adj[3][5] = adj[5][3] = 1;

    adj[4][5] = adj[5][4] = 1;
    adj[4][7] = adj[7][4] = 1;

    adj[5][6] = adj[6][5] = 1;
    adj[6][7] = adj[7][6] = 1;

    int N; cin >> N;
    vvi ans(8, vi(8, 0));
    for(int i=0;i<8;i++){
        ans[i][i] = 1;
    }
    while(N){
        if(N & 1)
            ans = mmult(ans, adj);
        adj = mmult(adj, adj);
        N /= 2;
    }
    cout << ans[0][0] << "\n";
    return 0;
}     