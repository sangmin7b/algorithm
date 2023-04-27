#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int dp[50];
int N;
string s;
vector<vector<string>> words;

int dist(string s1, string s2){
    int ans = 0;
    vi cnt(26,0);
    for(int i=0;i<s1.length();i++){
        cnt[s1[i]-'a']++;
        if(s1[i] != s2[i]){
            ans++;
        }    
    }
    for(char c:s2){
        cnt[c-'a']--;
    }
    for(int i=0;i<26;i++){
        if(cnt[i] != 0){
            ans = -1;
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i=0;i<=50;i++){
        dp[i] = 1e9;
    }
    cin >> s >> N;
    words = vector<vector<string>>(51);
    for(int i=0;i<N;i++){
        string word; cin >> word;
        words[word.length()].push_back(word);
    }
    dp[0] = 0;
    for(int i=1;i<=s.length();i++){
        for(int len=1;len<=min(i,(int)s.length());len++){
            for(string word:words[len]){
                int d = dist(word, s.substr(i-len,len));
                if(d == -1){
                    continue;
                }                
                dp[i] = min(dp[i], dp[i-len] + d);
            }
        }
    }
    if(dp[s.length()]<1e9){
        cout << dp[s.length()];
    }else{
        cout << -1;
    }
    return 0;
}     