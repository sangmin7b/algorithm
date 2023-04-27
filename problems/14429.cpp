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
    int ans_i = 0;
    int ans_l = 10000;
    for(int i=0;i<N;i++){
        int j, m;
        cin >> j >> m;
        int t = (j-1)/(m+1)*2 + 2;
        if(t < ans_l){
            ans_l = t;
            ans_i = i + 1;
        }
    }
    cout << ans_i << " " << ans_l << "\n";
    return 0;
}     