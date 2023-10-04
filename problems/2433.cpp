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
    int n, m, c; cin >> n >> m >> c;
    vi sample(n);
    for(int &x : sample) cin >> x;
    vi ans;
    deque<pi> min_q, max_q;
    for(int i = 0; i < n; i++){
        while(!min_q.empty() && min_q.front().second < i - m + 1){
            min_q.pop_front();
        }
        while(!min_q.empty() && min_q.back().first > sample[i]){
            min_q.pop_back();
        }
        min_q.push_back({sample[i], i});
        while(!max_q.empty() && max_q.front().second < i - m + 1){
            max_q.pop_front();
        }
        while(!max_q.empty() && max_q.back().first < sample[i]){
            max_q.pop_back();
        }
        max_q.push_back({sample[i], i});
        if(m - 1 <= i && max_q.front().first - min_q.front().first <= c) ans.push_back(i - m + 2);
    }
    if(ans.size()){
        for(int x: ans) cout << x << "\n";
    }else{
        cout << "NONE";
    }
    return 0;
}     