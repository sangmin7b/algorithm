#include<bits/stdc++.h>
using namespace std;

int max_val = -1e9;
int min_val = 1e9;
int ops[4];
int nums[11];
int N;

void dfs(int step, int tmp){
    if(step == N){
        max_val = max(max_val, tmp);
        min_val = min(min_val, tmp);
        return;
    }
    for(int i=0;i<4;i++){
        if(ops[i] == 0){continue;}
        ops[i]--;
        switch(i){
        case 0:
            dfs(step+1, tmp + nums[step]);
            break;        
        case 1:
            dfs(step+1, tmp - nums[step]);
            break;        
        case 2:
            dfs(step+1, tmp * nums[step]);
            break;        
        case 3:
            dfs(step+1, tmp / nums[step]);
            break;        
        }
        ops[i]++;
    }
    return;
}

int main(int argc, const char** argv) {
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    for(int i=0;i<4;i++){
        cin >> ops[i];
    }
    dfs(1, nums[0]);
    cout << max_val << "\n" << min_val << "\n";
    return 0;
}     