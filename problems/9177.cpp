#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vvi dp;
vvi selected;
string a, b, c;
int match(int a_i, int b_i){
    if(a_i == a.length() && b_i==b.length()){
        return 1;
    }    
    if(dp[a_i][b_i] != -1){
        return dp[a_i][b_i];
    }
    dp[a_i][b_i] = 0;
    int idx = a_i + b_i;
    if(a_i == a.length()){
        if(c[idx] == b[b_i]){
            dp[a_i][b_i] = match(a_i, b_i + 1);           
        }
        return dp[a_i][b_i];
    }
    if(b_i == b.length()){
        if(c[idx] == a[a_i]){
            dp[a_i][b_i] = match(a_i+1, b_i);           
        }
        return dp[a_i][b_i];
    }
    if(c[idx] == a[a_i]){
        dp[a_i][b_i] = match(a_i+1, b_i);
    }
    if(c[idx] == b[b_i]){
        dp[a_i][b_i] = dp[a_i][b_i] | match(a_i, b_i+1);
    }
    return dp[a_i][b_i];
}

int main(int argc, const char** argv) {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    string results[2] = {"no", "yes"};
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a >> b >> c;
        dp = vvi(a.length()+1, vi(b.length()+1, -1));
        int result = match(0, 0);
        cout << "Data set " << i + 1 << ": " << results[result] << "\n";
    }
    return 0;
}     