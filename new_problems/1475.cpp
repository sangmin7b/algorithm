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
    int N; cin >> N;
    vi price(N);
    for(auto &x : price) cin >> x;
    int M; cin >> M;
    if(N == 1){
        cout << 0;
        return 0;
    }
    vi ans;
    auto min_p = min_element(price.begin(), price.end());
    auto non_zero_min_p = min_element(price.begin() + 1, price.end());
    if(M < *non_zero_min_p){
        cout << 0;
        return 0;
    }
    int cost = *non_zero_min_p;
    ans.push_back(non_zero_min_p - price.begin());
    while(cost + *min_p <= M){
        ans.push_back(min_p - price.begin());
        cost += *min_p;
    }
    for(auto &digit: ans){
        for(auto it = price.end() - 1; it != price.begin() + digit; it--){
            if(cost + *it - price[digit] <= M){
                cost += *it - price[digit];
                digit = (it - price.begin()); 
                break;
            }
        }
    }
    for(auto x: ans) cout << x;
    return 0;
}     