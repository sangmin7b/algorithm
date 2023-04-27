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
    string a, b;
    cin >> a >> b;
    if(a.length() != b.length()){
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int i=0;i<a.length();i++){
        if(a[i] != b[i]){
            break;
        }
        if(a[i] == '8'){
            ans++;
        }
    }
    cout << ans;
    return 0;
}