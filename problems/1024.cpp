#include<bits/stdc++.h>
using namespace std;

int sum(int x){
    return (x - 1) * x / 2;
}

int main(int argc, const char** argv) {
    int N, L;
    cin >> N >> L;
    int m = L;
    while(0 < N - sum(m) && (N - sum(m)) % m != 0){
        m++;
    }
    if(N - sum(m) < 0 || m > 100){
        cout << -1;
    }else{
        int start = (N - sum(m)) / m;
        for(int i=0;i<m;i++){
            cout << start + i << " ";
        }
    }
    return 0;
}