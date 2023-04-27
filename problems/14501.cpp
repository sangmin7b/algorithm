#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> T(N);
    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin >> T[i] >> P[i];
    }
    vector<int> memo(N, 0);
    for(int i=N-1;i>=0;i--){
        int selected = 0;
        int next = 0;
        int not_selected = 0;
        if(i + T[i] < N)
            next = memo[i + T[i]];        
        if(i + T[i] <= N)
            selected = P[i];
        if(i < N - 1)
            not_selected = memo[i + 1];       
        memo[i] = max(selected + next, not_selected);
    }
    cout << memo[0];
    return 0;
}