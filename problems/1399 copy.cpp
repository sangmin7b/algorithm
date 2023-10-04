#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

int dig(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    if(ans < 10){
        return ans;
    }
    return dig(ans);
}

void solve(){
    int K, M; cin >> K >> M;
    vi res;
    int s = 1;
    for(int i=0;i<K;i++){
        s = dig(s);
        res.push_back(s);
        s *= M;
    }
    int cycle;
    for(int i=3;i<10;i++){
        if(res[i] == res[2]){
            cycle = i - 2;
            break;
        }
    }
    ll x = 0, y = 0;
    for(int i=0;i<K;i++){
        switch (i % 4){
        case 0:
            y += res[i];
            break;
        case 1:
            x += res[i];
            break;
        case 2:
            y -= res[i];
            break;
        case 3:
            x -= res[i];
            break;
        }
    }
    cout << x << " " << y << "\n";
}

int main(int argc, const char** argv) {
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}     