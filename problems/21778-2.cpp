#include <algorithm>
#include<bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, Q;

struct process{
    ll id, priority, load;
};

auto cmp = [](process &a, process &b) -> bool{
    if(a.priority == b.priority){
        return a.id < b.id;    
    }
    return a.priority > b.priority;
};

map<ll, int> query;
vl ans;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    priority_queue<process, vector<process>, decltype(cmp)> pq(cmp);
    cin >> Q >> N;
    for(int i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        pq.push({a, c, b});    
    }
    ans = vl(Q);
    ll max_t = 0;
    for(int i = 0; i < Q; i++){
        ll t; cin >> t;
        query[t] = i;
        max_t = max(max_t, t);
    }
    for(int i = 1; i < max_t; i++){
        process p = pq.top();
        pq.pop();
        p.load--;
        if(p.load){
            pq.push(p);
        }
        if(query.find(i) != query.end()){
            ans[query[i]] = p.id;
        }        
    }
    for(int x : ans){
        cout << x << "\n";
    }
    return 0;
}     