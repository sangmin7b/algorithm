#include<bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

pi f(int n, int x){
    if(n == 1){
        return (vector<pi>){(pi){0, 0}, {0, 1}, {1, 1}, {1, 0}}[x];
    }
    int block_size = 1 << (2 * n - 2);
    int w = 1 << (n - 1);
    auto [r, c] = f(n - 1, x % block_size);
    switch (x / block_size){
        case 0:
            return {c, r};
        case 1:
            return {r, c + w};
        case 2:
            return {r + w, c + w};
        case 3:
            return {2 * w - 1 - c, w - 1 - r};
    }
    return {0, 0};
}

void solve(){
    int n, h, o;
    cin >> n >> h >> o;
    h--; o--;
    pi from = f(n, h);
    pi to = f(n, o);  
    ll dr = from.first - to.first;
    ll dc = from.second - to.second;
    cout << round(sqrt(dr * dr + dc * dc) * 10) << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}