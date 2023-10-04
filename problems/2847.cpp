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
    int N; cin >> N;
    vi score(N);
    for(int &x : score){
        cin >> x;
    }
    int ans = 0;
    for(int i = N - 1; 0 < i; i--){
        if(score[i] <= score[i-1]){
            ans+= score[i-1] - score[i] + 1;
            score[i-1] = score[i] - 1;
        }
    }
    cout << ans;
    return 0;
}     