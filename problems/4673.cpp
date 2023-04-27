#include<bits/stdc++.h>

using namespace std;

bool is_selfnum[10001];

int d(int x){
    int acc = x;
    while(x){
        acc += x % 10;
        x /= 10;
    }
    return acc;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(is_selfnum,1,10001);

    for(int i = 1;i <= 10000;i++){
        for(int n = d(i);n != i && n <= 10000;n = d(n)){
            is_selfnum[n] = 0;
        }
    }
    for(int i = 1;i <= 10000;i++){
        if(is_selfnum[i]){
            cout << i << "\n";
        }
    }
    return 0;
}     