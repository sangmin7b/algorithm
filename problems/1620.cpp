#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M; cin >> N >> M;
    unordered_map<string, int> name_to_idx;
    vector<string> name(N+1);
    for(int i=1;i<=N;i++){
        string s; cin >> s;
        name[i] = s;
        name_to_idx[s] = i;
    }
    for(int i=0;i<M;i++){
        string s; cin >> s;
        if('0' <= s[0] && s[0] <= '9'){
            cout << name[stoi(s)] << "\n";
        }else{
            cout << name_to_idx[s] << "\n";
        }
    }
    return 0;
}     