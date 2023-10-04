#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    int S, T;
    cin >> S >> T;
    ll ans = 0;
    for(int i = 1; i <= T; i++){
        int start = (S + i - 1) / i * i;
        if(T < start)
            continue;
        int diff = ((T - start) / i) + 1;
        if(i % 2 == 0){
            ans += diff;
        }else{
            ans -= diff;
        }
    }
    cout << ans;
    return 0;
}     