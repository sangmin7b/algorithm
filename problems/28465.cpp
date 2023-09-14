#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int x, int y){
    if(a > b){
        return solve(b, a, y, x);        
    }
    if(a == 1 && b == 1){
        return 1;
    }
    if(y < b - a){
        return solve(b - a, a, y, x);
    }    
    if(a <= y){
        return solve(b - a, a, y - a, x);
    }
    int cnt = 1;
    while(a < b){
        b -= a;
        swap(a, b);
        cnt++;
    }
    return cnt;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b; cin >> a >> b;
    int x, y; cin >> x >> y;
    cout << solve(a, b, x, y);
    return 0;
}     