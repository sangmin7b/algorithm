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
    vl nums(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> nums[i];
    }
    deque<pl> dq;
    vl dp(N+1, 0);
    vl psum(N+1, 0);
    for(int i=1;i<=N;i++){
        psum[i] = psum[i-1] + nums[i];
    }
    dq.push_back({0,-1});
    dq.push_back({-psum[1],0});
    for(int i=1;i<=N;i++){
        //  i - K - 1 |  i - K  | i - K + 1 ~ i - 1 | i 
        while(!dq.empty() && dq.front().second < i-K-1){
            dq.pop_front();
        }
        dp[i] = dq.front().first + psum[i];
        if(i==N){
            break;
        }
        while(!dq.empty() && dq.back().first < dp[i] - psum[i+1]){
            dq.pop_back();
        }
        dq.push_back({dp[i] - psum[i+1], i});
    }
    cout << dp[N] << "\n";
    for(int x: dp){
        cout << x << " ";
    }
    return 0;
}     