#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll count(int left, int right){
    ll cnt = 0;
    for(int i=0;i<=left;i++){
        cnt += max(right + 1 + min(i - 2, 0), 0);
    }
    return cnt;
}

int solve(string s, char c){
    int left = 0;
    int right = 0;
    ll ans = 0;
    int cnt = 0;
    vector<int> v;
    for(int i=0;i<s.size();i++){
        if(s[i] != c){
            cnt++;
        }else{
            v.push_back(cnt);
            cnt = 0;
        }
    }
    v.push_back(cnt);
    for(int i=0;i<v.size()-1;i++){
        ans += count(v[i], v[i+1]);
    }
    return ans;
}

int main(int argc, const char** argv) {
    int N; cin >> N;
    string s; cin >> s;
    
    ll ans = solve(s, 'G') + solve(s, 'H');
    
    cout << ans;
    return 0;
}