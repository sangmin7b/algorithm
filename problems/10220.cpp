#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

/* 
1 :  X    
2 :  X  
3 :  x 
4 :  2 0 2 0
5 : 

*/

vi ltov(ll x){
    vi v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}

void solve(){
    int n = 4; cin >> n;
    queue<vi> q;
    q.push({2,0,2,0});
    q.push({1,2,1,0});
    cout << "case : " << n << "\n";
    for(ll i=0;i<pow(10, n);i++){
        vi v(n, 0);
        for(int j=0;j<n;j++){
            v[j] = (i / (int)pow(10, n-1-j)) % 10;            
        }
        bool ok = true;
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int x: v){
                if(x == j){
                    cnt++;
                }
            }
            if(cnt != v[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << i << "\n";
        }
    }    
    cout << "end\n";
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}