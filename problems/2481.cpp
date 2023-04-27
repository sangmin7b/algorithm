#include<bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int s_to_i(string& s){
    int res = 0;
    for(char c: s){
        res = res << 1;
        res = res | (c == '1');
    }
    return res;
}

vector<int> neighbors(int x, int K){
    vector<int> res;
    for(int i=0;i<K;i++){
        res.push_back(x ^ (1<<i));
    }
    return res;
}

vector<int> find_path(int start, int target, vector<vector<int>>& adj, vector<int>& ans){
    vector<bool> visited(adj.size(),0);
    queue<int> q;
    vector<int> prev(adj.size());
    visited[start] = 1;
    q.push(start);
    while(!q.empty() && (q.front() != target)){
        int now = q.front();
        q.pop();
        for(int next: adj[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
                prev[next] = now;
            }
        }
    }
    if(!visited[target]){
        ans.push_back(-1);
    }else{
        int now = target;
        ans.push_back(now);
        while(now != start){
            now = prev[now];
            ans.push_back(now);
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> adj(N, vector<int>());
    vector<int> nums;
    unordered_map<int, int> n_to_idx;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        int x = s_to_i(s);
        nums.push_back(x);
        n_to_idx.insert({x,i});
    }
    for(int i=0;i<N;i++){  
        for(int neighbor: neighbors(nums[i], K)){
            auto it = n_to_idx.find(neighbor);
            if(it != n_to_idx.end()){
                adj[i].push_back(it->second);
            }
        }
    }
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int target;
        cin >> target;
        target--;
        vector<int> ans;
        find_path(0, target, adj, ans);
        if(ans.size() == 1){
            cout << "-1\n";
        }else{
            for(auto it = ans.rbegin(); it != ans.rend();it++){
                cout << *it + 1<< " ";
            }
            cout << "\n";
        }
    }
    return 0;
}