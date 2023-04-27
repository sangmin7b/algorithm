#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int count_one(int n){
    int cnt = 0;
    for(int i=0;i<32;i++){
        if(n & (1<<i)){
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int ans = 0;
    while(K < count_one(N)){
        ans += N & (-N);
        N += N & (-N);
    }
    cout << ans;
    return 0;
}     