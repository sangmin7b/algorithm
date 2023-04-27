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
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    vi starts(N,1);
    vi ends(N,1);
    for(int i=1;i<N;i++){
        if(nums[i-1] < nums[i]){
            ends[i] = ends[i-1] + 1;
        }
    }
    for(int i=N-2;0<=i;i--){
        if(nums[i] < nums[i+1]){
            starts[i] = starts[i+1] + 1;
        }
    }
    int ans = 0;
    for(int i=0;i<N-K+1;i++){
        int s = 0, e = 0;
        int prev = 0, next = 1e9;
        if(0 < i){
            e = ends[i-1];
            prev = nums[i-1];
        }
        if(i < N - K){
            s = starts[i+K];
            next = nums[i+K];
        }
        int less_than_next = 0, greater_than_prev = 0;
        for(int j=i;j<i+K;j++){
            if(nums[j] < next){
                less_than_next++;
            }
            if(prev < nums[j]){
                greater_than_prev++;
            }
        }
        int cnt = 0;
        if(less_than_next == K && greater_than_prev == K){
            cnt = e + s + K;
        }else{
            cnt = max(less_than_next + s, greater_than_prev + e);
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}     