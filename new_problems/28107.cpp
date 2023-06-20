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
    int N, M;
    cin >> N >> M;
    priority_queue<pi, vector<pi>, greater<pi>> order;
    priority_queue<int, vi, greater<int>> sushi;
    for(int i = 0; i < N; i++){
        int A; cin >> A;
        for(int j = 0; j < A; j++){
            int x; cin >> x;
            order.push({x, i});
        }
    }
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        sushi.push(x);
    }
    vi ans(N, 0);
    while(!sushi.empty()){
        int x = sushi.top(); sushi.pop();
        while(!order.empty() && order.top().first < x){
            order.pop();
        }
        if(order.empty()){
            break;
        }
        if(order.top().first > x){ 
            continue;
        }
        ans[order.top().second]++;
        order.pop();
    }
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}     