#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int offset = 2000000;
int dp[4000001];
bool selected[40];
int nums[40];
ll ans = 0;
int N, S;
void dfs_l(int step, int step_end, int choice){
    if(step == step_end || choice == 0){
        int sum = 0; 
        for(int i=0;i<step_end;i++){
            if(selected[i]){
                sum += nums[i];
            }
        }
        if(0 <= offset+sum && offset + sum <= 4000000){
            dp[offset+sum]++;
        }
        return;         
    }
    if(step_end - step == choice){
        for(int i=step;i<step_end;i++){
            selected[i] = 1;
        }
        dfs_l(step_end, step_end, 0);
        for(int i=step;i<step_end;i++){
            selected[i] = 0;
        }
        return;
    }
    selected[step] = 1;
    dfs_l(step+1, step_end, choice-1);
    selected[step] = 0;
    dfs_l(step + 1, step_end, choice);
    return;
}

void dfs_r(int step, int step_end, int choice){
    if(step == step_end || choice == 0){
        ll sum = 0; 
        for(int i=0;i<step_end;i++){
            if(selected[i]){
                sum += nums[i];
            }
        }
        if(0 <= S + offset - sum && S + offset - sum <= 4000000){
            ans += dp[S + offset - sum];
        }
        return;         
    }
    if(step_end - step == choice){
        for(int i=step;i<step_end;i++){
            selected[i] = 1;
        }
        dfs_r(step_end, step_end, 0);
        for(int i=step;i<step_end;i++){
            selected[i] = 0;
        }
        return;
    }
    selected[step] = 1;
    dfs_r(step+1, step_end, choice-1);
    selected[step] = 0;
    dfs_r(step + 1, step_end, choice);
    return;        
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    for(int i=0;i<=N/2;i++){
        dfs_l(0,N/2,i);
    }
    for(int i=0;i<=(N+1)/2;i++){
        dfs_r(N/2,N,i);
    }
    if(S == 0){
        ans--;
    }
    cout << ans;
    return 0;
}   

/*
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1


*/