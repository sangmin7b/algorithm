#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char c){
    string vowels = "AEIOU";
    for(auto x : vowels){
        if(c == x) return true;
    }
    return false;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M; cin >> N >> M;
    string s; cin >> s;
    string ans = "";
    int state = 0;
    for(int i = N - 1; 0 <= i; i--){
        if(state == 0 && !is_vowel(s[i])){
            ans += s[i];
            state++;
        }else if(0 < state && state < 3 && s[i] == 'A'){
            ans += s[i];
            state++;
        }else if(3 <= state && state < M){
            ans += s[i];
            state++;
        }
    }
    if(state == M){
        cout << "YES\n";
        cout << string(ans.rbegin(), ans.rend());
    }else{
        cout << "NO";
    }
    return 0;
}     