#include<bits/stdc++.h>

using namespace std;

int adj[50][50];
int ans[50];
int N;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c; cin >> c;
            if(c == 'Y'){
                adj[i][j] = 1;
                ans[i]++;
            }else{
                adj[i][j] = 0;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=0;k<N;k++){
                if(adj[i][k] && adj[k][j] && !adj[i][j]){
                    ans[i]++;
                    ans[j]++;
                    break;
                }
            }
        }
    }
    cout << *max_element(ans, ans+N);
    return 0;
}     