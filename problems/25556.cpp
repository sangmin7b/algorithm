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
    int N;
    cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    stack<int> s[4];
    for(int x:nums){
        for(int i=0;i<4;i++){
            if(s[i].empty() || s[i].top() < x){
                s[i].push(x);
                goto next;
                break;
            }
        }
        cout << "NO";
        return 0;
        next:
        continue;
    }
    cout << "YES";
    return 0;
}     