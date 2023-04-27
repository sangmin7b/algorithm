#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int rev(int x){
    int a = 0;
    while(x){
        a *= 10;
        a += x % 10;
        x /= 10;
    }
    return a;
}

int solve(int x){
    for(int i=1;i<21e7;i++){
        if(i - rev(i) == x){
            return i;
            break;
        }
    }
    return -1;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int D;
    cin >> D;
    cout << solve(D) << "\n";
    return 0;
}     