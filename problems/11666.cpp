#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M; cin >> N >> M;
    priority_queue<int, vi, greater<int>> available, running;
    priority_queue<pi, vector<pi>, greater<pi>> users;
    int ans = 0;
    for(int i=0;i<N;i++){
        int a, s;
        cin >> a >> s;
        users.push({a, s});
    }
    while(!users.empty()){
        auto[start, duration] = users.top();
        users.pop();
        while(!running.empty() && running.top() < start){
            available.push(running.top() + M);
            running.pop();
        }
        while(!available.empty() && available.top() < start){
            available.pop();
        }
        if(!available.empty()){
            available.pop();
            ans++;
        }
        running.push(start + duration);
    }
    cout << ans << "\n";
    return 0;
}     