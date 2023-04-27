#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vl stock;
vl tree_size;
vvi children;
stringstream ss;
ll ans;
ll quota;

void get_tree_size(int node, int p){
    for(int child: children[node]){
        if(child == p){
            continue;
        }
        get_tree_size(child, node);
        tree_size[node] += tree_size[child];
        stock[node] += stock[child];
    }
    return;
}

void dfs(int node, pl p){
    vector<pl> v;
    for(int child: children[node]){
        if(child == p.first){
            continue;
        }
        ll diff = stock[child] - quota * tree_size[child];
        if(diff >= 0){
            dfs(child, {node, diff});
        }else{
            v.push_back({child, -diff});
        }
    }
    for(auto child: v){
        ss << node << " " << child.first << " " << child.second << "\n";
        ans++;
    }
    if(p.second != 0){
        ss << node << " " << p.first << " " << p.second << "\n";
        ans++;
    }
    for(auto child: v){
        dfs(child.first, {node, 0});
    }
    return;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll N;
    cin >> N;
    stock = vl(N+1,0);
    tree_size = vl(N+1,1);
    children = vvi(N+1);
    ll total = 0;
    for(int i=1;i<=N;i++){
        cin >> stock[i];
        total += stock[i];
    }
    quota = total / N;
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }
    
    get_tree_size(1, 0);
    dfs(1, {0,0});
    cout << ans << "\n";
    cout << ss.str();
    return 0;
}     