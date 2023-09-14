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
    int N, Q; cin >> N >> Q;
    vi pointer(N);
    vi ans(N);
    iota(pointer.begin(), pointer.end(), 0);
    for(int i = 0; i < Q; i++){
        int a, b, x; cin >> a >> b >> x;
        a--; b--;
        int idx = a;
        while(idx <= b){
            while(pointer[idx] != idx && idx <= b){
                int prev = idx;
                idx = pointer[idx];
                pointer[prev] = max(b + 1, pointer[prev]);
            }
            if(b < idx) break;
            ans[idx] = x;
            pointer[idx] = b + 1;
            idx++;
        }
    }   
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}     