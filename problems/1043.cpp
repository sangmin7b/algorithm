#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pil = pair<int, ll>;
using pii = pair<int, int>;

int main(int argc, const char** argv) {
    int N, M;
    cin >> N >> M;
    int K;
    cin >> K;
    set<int> p;
    for(int i=0;i<K;i++){
        int temp;
        cin >> temp;
        p.insert(temp);
    }
    vector<int>adj[M];
    vector<ll>parties(M,0);
    set<int> start_idx;
    for(int i=0;i<M;i++){
        int num_of_people;
        cin >> num_of_people;
        ll members = 0;
        for(int j=0;j<num_of_people;j++){
            int n;
            cin >> n;
            if(p.find(n) != p.end()){
                start_idx.insert(i);
            }
            n--;
            members |= ((ll)1 << n);
        }
        parties[i] = members;
    }

    for(int i=0;i<M-1;i++){
        for(int j=i+1;j<M;j++){
            if(parties[i] & parties[j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<bool> visited(M,0);
    function<void(int)> dfs = [&](int now)-> void{
        for(int next: adj[now]){
            if(visited[next]) continue;
            visited[next] = 1;
            dfs(next);
        }
        return;
    };

    for(int i: start_idx){
        visited[i] = 1;
        dfs(i);
    }
    int ans = count(visited.begin(), visited.end(), 0);
    cout << ans;

    return 0;
}