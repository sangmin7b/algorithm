#include<bits/stdc++.h>
using namespace std;

vector<bool> alive;
vector<int> score;
vector<vector<int>> R;
int N;
int U;

void kill(int i){
    alive[i] = 0;
    for(int j=0;j<score.size();j++){
        score[j] += R[i][j];
    }
}
void rkill(int i){
    alive[i] = 1;
    for(int j=0;j<score.size();j++){
        score[j] -= R[i][j];
    }
}

int argmax_alive(){
    int m = -987654321;
    int idx = -1;
    for(int i=0;i<score.size();i++){
        if(alive[i] && m < score[i]){
            m = score[i];
            idx = i;
        }
    }
    return idx;
}

int solve(int n){
    if(n == 1){
        return 1;
    }

    if(n % 2 == 1){
        int v = argmax_alive();
        if (v == U){
            return n;
        }
        alive[v] = 0;
        int res = solve(n-1);
        alive[v] = 1;
        return res;
    }else{
        int min_n = n;
        for(int i=0;i<score.size();i++){
            if(alive[i] && i != U){
                kill(i);
                min_n = min(min_n,solve(n-1));
                rkill(i);
            }
        }
        return min_n;
    }

}

int main(int argc, char const *argv[]){

    cin >> N;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        score.push_back(x);
    }
    alive = vector<bool>(N,1);
    R = vector<vector<int>>(N, vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> R[i][j];
        }
    }
    cin >> U; 
    cout << (N - solve(N) + 1) / 2;

    return 0;
}
