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
    int N, L;
    cin >> N >> L;
    deque<pi> q;
    for(int i = 0;i < N;i++){
        int x; cin >> x;
        while(!q.empty() && q.front().second <= i - L){
            q.pop_front();
        }
        while(!q.empty() && q.back().first >= x){
            q.pop_back();
        }
        q.push_back({x,i});
        cout << q.front().first << " ";
    }
    cout << "\n";
    return 0;
}     