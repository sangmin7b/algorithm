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

vector<int> find(string s1, string s2){
    vector<int> result;
    auto fail = get_pi(s2);
    for(int i=0, j=0;i<s1.size();i++){
        while(s1[i] != s2[j] && j > 0){
            j = fail[j-1];
        }
        if(s1[i] == s2[j]){
            j++;
            if(j == s2.size()){
                result.push_back(i - j + 1);
                j = fail[j-1];
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[]){
    string s, s2;
    cin >> s >> s2;
    for(int i: find(s, s2)){
        cout << i << " ";
    }    
    return 0;
}
