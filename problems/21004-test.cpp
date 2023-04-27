#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int gcd(int a, int b){
    if(a % b == 0){
        return b;
    }
    return gcd(b, a%b);
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N = 100000;
    //vi cnt(N+1,0);
    for(int i=1;i<=N;i++){
        int cnt = 0;
        for(int j=i+1;j<=N;j++){
            if(gcd(i,j) == (i^j)){
                cnt++;
            }
        }
        int cnt2 = 0;
        for(int j=1;j*j<=i;j++){
            if(i % j != 0){continue;}
            if((i & j) == 0){
                cnt2++;
            }
            if(j*j != i && j != 1 && (i & (i/j)) == 0){
                cnt2++;
            }
        }
        
        if(cnt != cnt2){
            cout << i << " " << cnt << " " << cnt2 << "\n";
        }
    }
    return 0;
}     