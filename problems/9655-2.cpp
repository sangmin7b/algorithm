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
    int op[3] = {0, 2, 1};
    int N;
    cin >> N;
    queue<int> q;
    vi ans(N, 0);
    ans[0] = 1;
    ans[2] = 1;
    q.push(0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int d: {1, 3}){
            int next = now + d;
            if(next < N && !ans[next]){
                ans[next] = op[ans[now]];
                q.push(next);
            }
        }
    }
    if(ans[N-1] == 1){
        cout << "SK\n";
    }else{
        cout << "CY\n";
    }
    return 0;
}     