#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

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
    string T, P;
    getline(cin, T);
    getline(cin, P);
    vi pi = get_pi(P);
    vi index_v;
    for(int i=0, j= 0;i<T.size();i++){
        while(T[i] != P[j] && j > 0){
            j = pi[j-1];
        }
        if(T[i] == P[j] && ++j == P.size()){
            index_v.push_back(i - j + 1);
            j = pi[j-1];
        }
    }
    cout << index_v.size() << "\n";
    for(int idx: index_v){
        cout << idx + 1 << " ";
    }
    return 0;
}