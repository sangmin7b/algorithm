#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    vl sum(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    ll ans = 0;
    for(int x=1;x<=N-2;x++){
        int min_y, max_y;
        int lo = x, hi = N;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(sum[N] - sum[mid] < sum[mid] - sum[x]){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        min_y = lo;
        lo = x; hi = N;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(sum[x] < sum[N] - sum[mid]){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        max_y = lo;
        if(min_y == x || max_y == x || min_y == N || max_y == N){continue;}
        ans += max((max_y - min_y + 1),0);
    }
    cout << ans << "\n";
    return 0;
}