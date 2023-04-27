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
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int ans = 0;
    vi visited(N+1, 1);
    queue<int> nums, q;
    for(int i=1;i<=N;i++){
        nums.push(i);
    }
    for(int i=0;i<M;i++){
        int x; cin >> x;
        q.push(x);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int cnt = 0;
        while(nums.front() != x){
            nums.push(nums.front());
            nums.pop();
            cnt++;
        }
        ans += min(cnt, (int)nums.size() - cnt);
        nums.pop();
    }
    cout << ans;
    return 0;
}     