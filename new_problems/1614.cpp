#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, const char** argv) {
    ll x; cin >> x;
    ll cnt; cin >> cnt;
    ll ans = 0;
    if(x == 1 || x == 5){
        ans += cnt * 8;
        ans += x - 1;
    }else{
        ans += cnt / 2 * 8;
        if(cnt % 2 == 1){
            ans += 9 - x;
        }else{
            ans += x - 1;
        }
    }
    cout << ans;
    return 0;
}     