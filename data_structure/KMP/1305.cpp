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

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int ans = 0;
    auto pi = get_pi(s);
    ans = s.size() - pi.back();
    cout << ans;
    pi.back();
    return 0;
}