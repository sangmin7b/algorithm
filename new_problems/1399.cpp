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
    for(int i=0;i<30;i++){
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
    if(K == 1){
        cout << 0 << " " << res[0] << "\n";
        return;
    }
    if(K == 2){
        cout << res[1] << " " << res[0] << "\n";
        return;
    }
    int p = 4 * cycle;
    ll x = 0, y = 0;
    y += res[0];
    x += res[1];
    ll dx = 0, dy = 0;
    for(int i=2;i<2+p;i+=4){
        dy -= res[i];
    }
    for(int i=4;i<4+p;i+=4){
        dy += res[i];
    }
    for(int i=5;i<5+p;i+=4){
        dx += res[i];
    }
    for(int i=3;i<3+p;i+=4){
        dx -= res[i];
    }
    int T = (K - 2) / p;
    int R = (K - 2) % p;
    x += dx * T;    
    y += dy * T;    
    for(int i=2;i<2+R;i+=4){
        y -= res[i];
    }
    for(int i=4;i<2+R;i+=4){
        y += res[i];
    }
    for(int i=5;i<2+R;i+=4){
        x += res[i];
    }
    for(int i=3;i<2+R;i+=4){
        x -= res[i];
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