#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    const int MAX_N = 500001;
    vector<int> adj(500001, -1);
    vector<int> prev(500001, -1);
    vector<int> ordered;
    set<int> A;
    for(int i=0;i<N;i++){
        int a, b;
        cin >> a >> b;
        adj[b] = a;
        A.insert(a);        
    }
    for(int i=1;i<MAX_N;i++){
        if(adj[i] == -1){
            continue;
        }
        auto it = upper_bound(ordered.begin(), ordered.end(), adj[i]);
        if(it == ordered.end()){
            ordered.push_back(adj[i]);
        }else{
            prev[adj[i]] = *it;
            *it = adj[i];
        }
    }

     for(int i=ordered.size()-2;i>=0;i--){
        int x = ordered[i];
        while(prev[x] != -1 && prev[x] < ordered[i+1]){
            x = prev[x];
        }
        ordered[i] = x;
    }
    set<int> selected;
    for(int x: ordered){
        A.erase(x);
    }

    cout << A.size() << "\n";
    // for(int a: A){
    //     cout << a << "\n";
    // }


    return 0;
}