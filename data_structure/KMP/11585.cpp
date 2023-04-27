#include<bits/stdc++.h>
#include <sstream>
using namespace std;

// pi[j-1]: j에서 틀렸을 때 다음으로 살펴볼 j
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

int gcd(int a, int b){
    if(a < b)
        return gcd(b, a);
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<char> chars(N);
    vector<char> chars2(N);
    for(int i=0;i<N;i++){
        cin >> chars[i];
    }
    for(int i=0;i<N;i++){
        cin >> chars2[i];
    }
    string s = string(chars.begin(), chars.end());
    string s2 = string(chars2.begin(), chars2.end());
    s2 = s + s;
    auto v = find(s2, s);
    int a = v.size() - 1;
    int b = N;
    int g = gcd(b, a);
    cout << a/g << "/" << b/g;
    return 0;
}