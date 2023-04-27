#include<bits/stdc++.h>
using namespace std;
using piv = pair<int, vector<int>>;
const int INF = 1E6;
int main(int argc, const char** argv) {
    int N, T;
    cin >> N >> T;
    vector<int> value(N,0);
    vector<int> num_of_coins(N,0);
    for(int i=0;i<N;i++){
        cin >> value[i];
    }
    for(int i=0;i<N;i++){
        cin >> num_of_coins[i];
    }
    int max_T = 120 * 118;
    vector<int> memo(max_T + 1, INF);
    vector<piv> l_memo(max_T + 1, {INF, vector<int>(N, 0)});
    memo[0] = 0;
    l_memo[0].first = 0;
    for(int now=0;now<=max_T;now++){
        for(int i=0;i<N;i++){
            int next = now + value[i];
            if(next > max_T)
                continue;
            memo[next] = min(memo[next], memo[now] + 1);
            if(l_memo[now].second[i] < num_of_coins[i] && l_memo[next].first > l_memo[now].first + 1){
                l_memo[next].first = l_memo[now].first + 1;
                l_memo[next].second[i] = l_memo[now].second[i] + 1;
            }
        }
    }
    int ans = INF;
    for(int t=T;t<=max_T;t++){
        ans = min(ans, memo[t-T] + l_memo[t].first);
    }
    if(ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}