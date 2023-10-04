#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vector<pl> dq;
vector<pl> lines;
vl sum, dp, nums;
int a, b, c;
int s, e;
double cross(pl &p1, pl &p2){
    return (double) (p1.second - p2.second) / (p2.first - p1.first); 
};

pl get_line(int i){
    return {-2 * a * sum[i], dp[i] + a * sum[i] * sum[i] - b * sum[i]};
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    // dp[i] = max(dp[j] + f(sum(x[j+1..i])))
    // dp[i] = max(dp[j] + f(sum[i] - sum[j]))
    // dp[i] = max(dp[j] + a(sum[i] - sum[j]) ^ 2 + b(sum[i] - sum[j]) + c)
    // dp[i] = max(dp[j] + a * sum[i] ^ 2 - 2 * a * sum[i] * sum[j] + a * sum[j] ^ 2 + b * sum[i] - b * sum[j] + c)
    // dp[i] = a * sum[i] ^ 2 + b * sum[i] + c + max(dp[j] - 2 * a * sum[i] * sum[j] + a * sum[j] ^ 2 - b * sum[j])
    // dp[i] = a * sum[i] ^ 2 + b * sum[i] + c + 
    // max(-2 * a * sum[j] * sum[i]  
    //     + dp[j] + a * sum[j] ^ 2 - b * sum[j]
    // )
    cin >> a >> b >> c;
    sum = vl(N + 1, 0);
    dp = vl(N + 1, 0);
    dq = vector<pl>(N);
    for(int i = 1; i <= N; i++){
        cin >> sum[i]; sum[i] += sum[i - 1];
    }    
    for(int i = 1; i <= N; i++){
        ll v = a * sum[i] * sum[i] + b * sum[i] + c; 
        while(s + 1 < e && cross(dq[s], dq[s+1]) < sum[i]){   
            s++;
        }
        if(s < e && 0 < dq[s].first * sum[i] + dq[s].second){
            v += dq[s].first * sum[i] + dq[s].second;
        }
        dp[i] = v;
        pl p = get_line(i);
        while(s + 1 < e){
            if(cross(dq[e-1], p) < cross(dq[e-2], dq[e-1])){
                e--;
            }else{
                break;
            }
        }
        dq[e++] = p;
        // cout << "i " << i << " line: " << p.first << " " << p.second << "\n";
        // cout << "s : " << s << " e : " << e << "\n";
    }
    // for(int i = 1; i <= N; i++){
    //     cout << dp[i] << " ";
    // }
    cout << dp[N];
    return 0;
}     