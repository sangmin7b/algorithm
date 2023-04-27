#include<bits/stdc++.h>
using namespace std;
int file[501];
int cost[501][501];
int size_sum[501];
const int inf = 1e9;
int _solve(int start, int end){
    if(cost[start][end] != -1)
        return cost[start][end];
    if(start == end)
        return cost[start][end] = 0;
    int res = inf;
    for(int i=start;i<end;i++){
        int r = _solve(start, i) + _solve(i+1,end) + size_sum[end+1] - size_sum[start];
        res = min(res, r);
    }   
    cost[start][end] = res;
    return res;
}

void solve(){
    int N; cin >> N;
    for(int i=0;i<N;i++){
        cin >> file[i];
    }
    for(int i=0;i<N;i++){
        size_sum[i+1] = size_sum[i] + file[i];
    }
    memset(cost, -1, sizeof(cost));
    int ans = _solve(0,N-1);
    cout << ans << "\n";
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}