#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    string ans;
    cin >> ans;
    for(int i=1;i<N;i++){
        string s;
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(ans[i] != s[i]){
                ans[i] = '?';
            }
        }
    }

    cout << ans;
    return 0;
}