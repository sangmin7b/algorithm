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
    vvi sum(3);
    for(int i = 0; i < N; i++){
        vi x(3);
        int s = 0;
        for(int j = 0; j < 3; j++){
            cin >> x[j];
            s += x[j];
        }
        for(int j = 0; j < 3; j++){
            sum[j].push_back(s - x[j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < 3; i++){
        sort(sum[i].begin(), sum[i].end(), greater<int>());
    }
    for(int i = 0; i < 3; i++){
        int s = 0;
        for(int j = 0; j < K; j++){
            s += sum[i][j];
        }
        ans = max(ans, s);
    }
    cout << ans;
    return 0;
}     