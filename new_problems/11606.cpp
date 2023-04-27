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
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int safe = 1;
    int broken = K;
    for(int i=0;i<N;i++){
        int x; string s;
        cin >> x >> s;
        if(s == "SAFE"){
            safe = max(safe, x);
        }else{
            broken = min(broken, x);
        }
    }
    cout << safe + 1 << " " << broken - 1;
    return 0;
}     