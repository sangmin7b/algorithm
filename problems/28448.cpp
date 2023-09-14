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
    ll N, L; cin >> N >> L;
    priority_queue<pl> pq;
    ll t_sum = 0;
    for(int i = 0; i < N; i++){
        ll K, T; cin >> K >> T;
        pq.push({min(K * T, 5 * K), K * T});
        t_sum += T;
    }
    ll ans = t_sum;
    ll m = 0;
    while(!pq.empty()){
        auto[x, p] = pq.top(); pq.pop();
        if(m + p > L){
            ans += m + p - L;
            m = L - x;
        }else{
            m += p - x;
        }    
    }
    cout << ans;
    return 0;
}     