#include<bits/stdc++.h>
#include <unordered_map>

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
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    stack<pi> s;
    vi ans(N,-1);
    for(int i=0;i<N;i++){
        while(!s.empty() && s.top().first < nums[i]){
            ans[s.top().second] = nums[i];
            s.pop();
        }
        s.push({nums[i],i});
    }
    for(int x: ans){
        cout << x << " ";
    }
    return 0;
}     