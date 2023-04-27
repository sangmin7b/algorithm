#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(int argc, const char** argv) {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pii> queries;
    for(int i=0;i<N;i++){
        int s, e;
        cin >> s >> e;
        queries.push_back({s, e});
    }
    int ans = 0;
    cout << ans;
    return 0;
}
