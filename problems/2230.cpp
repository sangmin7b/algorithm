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
    int N, M;
    cin >> N >> M;
    vi A(N, 0);
    for(int &x : A){
        cin >> x;
    }
    sort(A.begin(), A.end());
    int idx_l = 0, idx_r = 1;
    int ans = 2e9;
    while(idx_l < N){
        while(idx_r < N - 1 && A[idx_r] - A[idx_l] < M){
            idx_r++;
        }
        if(M <= A[idx_r] - A[idx_l])
            ans = min(ans, A[idx_r] - A[idx_l]);
        idx_l++;
    }    
    cout << ans;
    return 0;
}     