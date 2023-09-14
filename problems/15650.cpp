#include<bits/stdc++.h>
using namespace std;

int selected[8];
int N, M;

void sol(int x, int cnt){
    if(N < x){
        return;
    }
    if(cnt == M){
        for(int i = 0; i < N; i++){
            if(selected[i]){
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        return;
    }
    selected[x] = 1;    
    sol(x + 1, cnt + 1);
    selected[x] = 0;    
    sol(x + 1, cnt);
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    sol(0, 0);
    return 0;
}     