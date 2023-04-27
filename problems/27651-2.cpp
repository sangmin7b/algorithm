#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    vi nums(N+1,0);
    vi sum(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> nums[i];
        sum[i] = sum[i-1] + nums[i];
    }
    ll ans = 0;
    for(int x=1;x<=N-2;x++){
        for(int )
    }
    cout << ans << "\n";
    return 0;
}     