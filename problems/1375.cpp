#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vvi adj;
vi visited;

bool search(int now, int key){
    visited[now] = true;
    for(int next: adj[now]){
        if(visited[next]){
            continue;
        }
        if(next == key){
            return true;
        }
        if(search(next, key)){
            return true;
        }
    }
    return false;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    adj = vvi(N, vi());
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >>  b;
        a--; b--;
        bool res[2];
        visited = vi(N, 0);
        res[0] = search(a, b);
        visited = vi(N, 0);
        res[1] = search(b, a);
        if(res[0] == res[1]){
            cout << "gg ";
            continue;
        }
        if(res[0]){
            cout << a + 1 << " ";
        }else{
            cout << b + 1 << " ";
        }
    }
    return 0;
}     