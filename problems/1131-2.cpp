#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vi visited(4000001, 0);
vi is_cycle(4000001, 0);
vi dp(4000001, 1e9);
vi next_x(4000001, 0);
vi pow_k(10, 0);
int A, B, K;

int Sk(int x){
    int ans = 0;
    while(x){
        ans += pow_k[x % 10];
        x /= 10;
    }
    return ans;
}

void find_cycle(int x, int from){
    while(!is_cycle[x]){
        visited[x] = from;
        if(visited[next_x[x]] == from){ 
            is_cycle[x] = 1;
        }
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
        next_x[i] = Sk(i);
    }
    for(int i=0;i<=4000000;i++){
        if(!visited[i]){
            find_cycle(i, i);
        }
    }
    for(int i=0;i<=4000000;i++){
        if(is_cycle[i] && dp[i] == 1e9){
            int min_x = i;
            int x = next_x[i];
            while(x != i){
                min_x = min(min_x, x);
                x = next_x[x];
            }
            dp[i] = min_x;
            x = next_x[i];
            while(x != i){
                dp[x] = min_x;
                x = next_x[x];
            }
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