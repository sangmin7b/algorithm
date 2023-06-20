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
    for(int i = 0; i < 3; i++){
        int N; cin >> N;
        ll s = 0;
        for(int j = 0; j < N; j++){
            ll x; cin >> x;
            s += x;
        }
        if(0 < s){
            cout << "+\n";
        }else if(s < 0){
            cout << "-\n";
        }else{
            cout << "0\n";
        }
    }
    return 0;
}     