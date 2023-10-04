#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

vi visited(4000001, -1);
vi dp(4000001, 1e9);
vi next_x(4000001, 0);
vi pow_k(10, 0);
int A, B, K;

int f(int x){
    int ans = 0;
    while(x){
        ans += pow_k[x % 10];
        x /= 10;
    }
    return ans;
}

void find_cycle(int x, int from){
    while(visited[x] == -1){
        visited[x] = from;
        x = next_x[x];
    }
    if(visited[x] != from){
        return;
    }
    int start = x;
    int min_x = x;
    x = next_x[x];
    while(x != start){
        min_x = min(min_x, x);
        x = next_x[x];
    }
    dp[x] = min_x;
    while(x != start){
        dp[x] = min_x;
        x = next_x[x];
    }
    return;
}

int dfs(int x){
    if(dp[x] != 1e9){
        return dp[x];
    }
    dp[x] = min(x, dfs(next_x[x]));
    return dp[x];
}

int main(int argc, const char** argv) {    
    cin >> A >> B >> K;
    for(int i=1;i<=9;i++){
        int k = K;
        pow_k[i] = 1;
        while(k--){
            pow_k[i] *= i;
        }
    }
    for(int i=0;i<=4000000;i++){
        next_x[i] = f(i);
    }
    for(int i=0;i<=4000000;i++){
        if(visited[i] == -1){
            find_cycle(i, i);
        }
    }
    for(int i=0;i<=4000000;i++){
       dfs(i);
    }
    ll ans = 0;
    for(int i=A;i<=B;i++){
        ans += dp[i];
    }
    cout << ans;
    return 0;
} 