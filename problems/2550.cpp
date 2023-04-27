#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> i_to_out(N,0);
    vector<int> in_to_i(N+1,0);
    vector<int> i_to_in(N,0);
    vector<int> before(N,-1);

    vector<int> adj(N,0);
    for(int i=0;i<N;i++){
        cin >> i_to_out[i];
    }
    for(int i=0;i<N;i++){
        int x; cin >> x;
        in_to_i[x] = i;
        i_to_in[i] = x;
    }
    for(int i=0;i<N;i++){
        adj[in_to_i[i_to_out[i]]] = i;
    }

    vector<int> ordered;
    int s = 0;
    for(int x: adj){
        auto u = upper_bound(ordered.begin(), ordered.end(), x);
        if(u == ordered.end()){
            ordered.push_back(x);
        }else{
            before[x] = *u;
            *u = x;
        }
    }
    for(int i=ordered.size()-2;i>=0;i--){
        int x = ordered[i];
        while(before[x] != -1 && before[x] < ordered[i+1]){
            x = before[x];
        }
        ordered[i] = x;
    }

    vector<int> ans;
    for(int x: ordered){
        ans.push_back(i_to_out[x]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int x: ans){
        cout << x << " ";
    }

    return 0;
}