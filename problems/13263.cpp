#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

double cross(pl &p1, pl &p2){
    return (double) (p1.second - p2.second) / (p2.first - p1.first);
}

// 마지막을 나무를 자르기 전까지는 이미 자른 마지막 나무보다 앞에 있는 나무를 자를 필요 없음
// dp[i] = i번 나무를 전부 자른 뒤 마지막 나무를 전부 자를때까지 추가적으로 발생하는 충전 비용
// dp[i] = min(B[i] * A[j] + dp[j]) (i < j), {A[j], dp[j]}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vl A(N), B(N);
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;
    vl dp(N, 1e18);
    dp[N-1] = 0;
    vector<pl> lines(N);
    int s = 0, e = 0;
    lines[e++] = {A[N-1], dp[N-1]};
    for(int i = N - 2; 0 <= i; i--){
        while(s + 1 < e && cross(lines[s], lines[s+1]) < B[i]){   
            s++;
        }
        if(s < e){
            dp[i] = lines[s].first * B[i] + lines[s].second;
        }
        pl p = {A[i], dp[i]};
        while(s + 1 < e && cross(lines[e-1], lines[e-2] ) > cross(lines[e-1], p)){
            e--;
        }
        lines[e++] = p;     
    }
    ll ans = lines[s].first * B[0] + lines[s].second;
    cout << ans;
    return 0;
}     