#include<bits/stdc++.h>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    vi R(M,0);
    ll ans = 0;
    int offset = 0;
    for(int i=0;i<N;i++){
        offset -= nums[i];
        offset = (M + (offset % M) ) % M;
        R[(nums[i]+offset) % M]++;
        ans += R[offset];
    }
    cout << ans;
    return 0;
}