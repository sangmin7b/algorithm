#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    string s; cin >> s;
    string v[8] = {
        "0", "1", "10", "11", "100", "101", "110", "111"
    }; 
    cout << v[s[0] - '0'];
    for(int i=1;i<s.size();i++){
        cout << (((s[i] - '0') & 4) >> 2);
        cout << (((s[i] - '0') & 2) >> 1);
        cout << ((s[i] - '0') & 1);
    }
    return 0;
}     