#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> mem(N,0);
    vector<int> cost(N,0);
    for(int i=0;i<N;i++){
        cin >> mem[i];
    }
    for(int i=0;i<N;i++){
        cin >> cost[i];
    }
    vector<vector<int>> max_m(2,vector<int>(10001,0));
    for(int i=0;i<N;i++){
        int now = i & 1;
        int prev = now ^ 1;
        for(int j=0;j<=10000;j++){
            if(j>=cost[i]){
                max_m[now][j] = max(mem[i] + max_m[prev][j-cost[i]], max_m[prev][j]);
            }else{
                max_m[now][j] = max_m[prev][j];
            }
        }
    }    
    int ans = 0;
    int now = (N & 1) ^ 1;
    while(max_m[now][ans] < M){
        ans++;
    }    
    cout << ans;
    return 0;
}