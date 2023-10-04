#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using process = pair<int, pair<int, int>>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T, n;
    cin >> T >> n;
    priority_queue<process> pq;
    for(int i = 0; i < n; i++){
        int id, work_load, priority;
        cin >> id >> work_load >> priority;
        pq.push({priority, {-id, work_load}});
    }
    while(!pq.empty() && T--){
        process p = pq.top(); pq.pop();
        cout << -p.second.first << "\n";
        if(1 < p.second.second){
            pq.push({p.first - 1, {p.second.first, p.second.second - 1}});
        }
    }
    return 0;
}     