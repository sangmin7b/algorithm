#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[81][10];

int main(int argc, const char** argv) {
    for(int i=0;i<=9;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=80;i++){
        for(int j=0;j<=9;j++){
            for(int k=j;k<=9;k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        bool ok = true;
        char c = '0';
        for(char x: s){
            if(c > x){
                ok = false;
            }
            c = x;
        }
        if(!ok){
            cout << -1 << "\n";
        }else{
            ll ans = 0;
            for(int j=0;j<=s[0]-'0';j++){
                ans += dp[s.length()][j];
            }
            for(int i=1;i<s.length();i++){
                for(int j=s[i]-'0'+1;j<=9;j++){
                    ans -= dp[s.length()-i][j];
                }
            }
            cout << ans - 1 << "\n";
        }
    }
    return 0;
}     