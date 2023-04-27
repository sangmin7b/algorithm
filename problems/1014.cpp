#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<int>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, R, C;
    cin >> N >> R >> C;
    R++; C++;
    int ans = 0;
    while(N > 0){
        int s = 1 << (N - 1);
        if(R > s){
            ans += 2 * s * s; 
            R -= s;
        }
        if(C > s){
            ans += s * s;
            C -= s;
        }
        N--;
    }
    cout << ans;
    return 0;
}