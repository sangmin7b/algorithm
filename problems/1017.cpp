#include<bits/stdc++.h>
using namespace std;
int N;
set<int> primes;    
void calc_primes(){
    int n = 2001;
    vector<bool> is_prime(n,1);
    is_prime[0] = is_prime[1] = 0;
    for(int i=2;i<n;i++){
        if(!is_prime[i]){
            continue;
        }
        for(int j=2*i;j<n;j+=i){
            is_prime[j] = 0;
        }
    }
    for(int i=2;i<n;i++){
        if(is_prime[i]){
            primes.insert(i);
        }
    }
}

int visited[50];
int arr[50];
int matched[50];
vector<int> adj[50];
bool dfs(int now){
    if(visited[now]){
        return false;
    }
    visited[now] = 1;
    for(int next: adj[now]){
        if(visited[next]){
            continue;
        }
        if(matched[next] == -1 || dfs(matched[next])){
            matched[next] = now;
            return true;
        }
    }
    return false;
} 

bool match(int x){
    for(int i=0;i<N;i++){
        matched[i] = -1;
    }
    matched[x] = 0;

    bool ok = true;
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[j] = 0;
        }
        visited[0] = 1;
        matched[x] = 0;
        if (dfs(i)){
            cnt++;
        }
    }
    return (cnt == N-2);
}

int main(int argc, char const *argv[]){
    calc_primes();
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int s = arr[i] + arr[j];
            if(primes.find(s) != primes.end()){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> ans;
    for(int j: adj[0]){
        if(match(j)){
            ans.push_back(arr[j]);
        }
    }
    if(ans.empty()){
        cout << -1;
    }else{
        sort(ans.begin(), ans.end());
        for(int i: ans){
            cout << i << " ";
        }
    }

    return 0;
}