#include<bits/stdc++.h>
using namespace std;

int s, N, K, r1, r2, c1, c2;

int pow(int N, int k){
    int r = 1;
    while(k--){
        r *= N;
    }
    return r;
}

int state(int r, int c){
    int d = (N - K) / 2;
    for(int i = 0; i <= s; i++){
        if(d <= r / pow(N, s - i) && r / pow(N, s - i) < N - d  &&
            d <= c / pow(N, s - i) && c / pow(N, s - i) < N - d
        ){
            return 1;
        }
        r = r % pow(N, s - i);
        c = c % pow(N, s - i);
    }
    return 0;
}

int main(int argc, const char** argv) {
    cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;
    for(int r = r1; r <= r2; r++){
        for(int c = c1; c <= c2; c++){
            cout << state(r, c);
        }
        cout << "\n";
    }
    return 0;
}     