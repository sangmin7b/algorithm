#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1000];
int in_degree[1000];
int N, M;


int main(int argc, char const *argv[]){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int C;
        cin >> C;
        vector<int> singers;
        for(int i=0;i<C;i++){
            int s;
            cin >> s;
            singers.push_back(s-1);
        }        

        for(int i=0;i<singers.size()-1;i++){
            int from = singers[i];
            int to = singers[i+1];
            adj[from].push_back(to); 
            in_degree[to]++;
        }
    }
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<N;i++){
        
        if(in_degree[i]==0){
            q.push(i);
            ans.push_back(i);
        }
    }
    while((!q.empty())){
        int now = q.front();
        q.pop();
        for(int next: adj[now]){
            in_degree[next]-- ;
            if(in_degree[next] == 0){
                q.push(next);
                ans.push_back(next);
            }
        }
    }

    if(ans.size() == N){
        for(int i:ans){
            cout << i + 1 << "\n";
        }
    }else{
        cout << 0;
    }


    return 0;
}
