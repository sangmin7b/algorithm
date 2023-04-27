#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int G, P;
    cin >> G >> P;
    vector<int> g(P,0);
    set<int, greater<int>> s;
    for(int i=1;i<=G;i++){
        s.insert(i);
    }
    for(int i=0;i<P;i++){
        cin >> g[i];
    }
    int ans = 0;
    for(int i=0;i<P;i++){
        auto it = s.lower_bound(g[i]);
        if(it == s.end()){
            break;
        }
        s.erase(it);
        ans++;
    }
    cout << ans;
    return 0;
}