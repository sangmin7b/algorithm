#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

vector<int> get_pi(string s){
    vector<int> pi(s.size(),0);
    for(int i=1;i<s.size();i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j]) 
            pi[i] = ++j;
    }
    return pi;
}

int main(int argc, char const *argv[]){
    string s;
    cin >> s;
    int ans = 0;
    for(auto it = s.begin(); it != s.end();it++){
        auto pi = get_pi(string(it, s.end()));
        ans = max(ans, *max_element(pi.begin(), pi.end()));
    }
    cout << ans;
    return 0;
}
