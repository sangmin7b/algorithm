#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    string s; cin >> s;
    int cnt = N / 2;
    for(int i=0;i<N;i++){
        if(s[i] == '('){
            cnt--;
        }
    }
    for(int i=0;i<N;i++){
        if(0 < cnt && s[i] == 'G'){
            s[i] = '(';
            cnt--;
        }
    }
    for(int i=0;i<N;i++){
        if(s[i] == 'G'){
            s[i] = ')';
        }
    }
    cout << s;    
    return 0;
}     