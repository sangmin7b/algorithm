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
    int M, N, L; cin >> M >> N >> L;
    vi shooter(M);    
    set<int> right;
    set<int, greater<int>> left;
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        right.insert(x);
        left.insert(x);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        if(right.lower_bound(x) != right.end()){
            int s = *right.lower_bound(x);
            if(s - x + y <= L){
                ans++;
                continue;
            }
        }
        if(left.lower_bound(x) != left.end()){
            int s = *left.lower_bound(x);
            if(x - s + y <= L){
                ans++;
                continue;
            }
        }
    }
    cout << ans;
    return 0;
}     