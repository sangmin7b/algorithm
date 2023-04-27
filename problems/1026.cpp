#include<bits/stdc++.h>
#include <queue>

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
    int N;
    cin >> N;
    priority_queue<int, vi, greater<int>> A;
    priority_queue<int> B;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        A.push(x);
    }
    for(int i=0;i<N;i++){
        int x; cin >> x;
        B.push(x);
    }
    int ans = 0;
    while(!A.empty()){
        ans += A.top() * B.top();
        A.pop();
        B.pop();
    }
    cout << ans << "\n";
    return 0;
}     