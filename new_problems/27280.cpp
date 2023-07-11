#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
int H[1001];
int S[1001];
ll dp[11][1001];

int main(int argc, const char** argv) {
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> H[i] >> S[i];
    }    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= min(M, i); j++){
            ll max_s = 0;
            int max_h = 0;
            for(int k = i; j - 1 < k; k--){
                if(max_h < H[k]){
                    max_h = H[k];
                    max_s = S[k];
                }else if(max_h == H[k]){
                    max_s += S[k];
                }
                dp[j][i] = max(dp[j][i], dp[j-1][k-1] + max_s);
            }
        }
    }   
    cout << dp[M][N];
    return 0;
}     