#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(int argc, const char** argv) {
    ll N; cin >> N;
    ll ans = 0;
    for(int i = 0; i < 63; i++){
        if((1LL << i) & N){
            ans = i;
        }
    }
    if((1LL << ans) < N){
        ans++;
    }
    if(N == 0){
        cout << 0;
    }else{
        cout << ans + 1;
    }
    return 0;
}   