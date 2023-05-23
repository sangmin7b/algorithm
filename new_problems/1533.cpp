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

const int MOD = 1e6 + 3;

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

void madd(matrix &A, const matrix &B){
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            A[i][j] += B[i][j];
            A[i][j] %= MOD;
        }
    }
    return;
}

int main(int argc, const char** argv) {
    int N, S, E, T;
    cin >> N >> S >> E >> T;
    vvi adj(5 * N, vi(5 * N));    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){            
            char x; cin >> x;
            x -= '0';
            if(0 < x){
                adj[5 * i][5 * j + x - 1] = 1;
            }
        }        
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<5;j++){
            adj[5*i+j][5*i+j-1] = 1;
        }
    }
    vvi ans(5 * N, vi(5 * N, 0));
    for(int i=0;i<5*N;i++){
        ans[i][i] = 1;
    }
    while(0 < T){
        if((T & 1) == 1){
            ans = mmult(ans, adj);
        }
        adj = mmult(adj, adj);
        T /= 2;
    }
    cout << ans[5*(S-1)][5*(E-1)] << "\n";
    return 0;
}     
