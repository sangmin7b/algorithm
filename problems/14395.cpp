#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(int argc, const char** argv) {
    ll s, t;
    cin >> s >> t;
    queue<ll> q;
    function<ll(ll)> mul = [](ll x){
        return x * x;
    };
    function<ll(ll)> add = [](ll x){
        return x + x;
    };
    function<ll(ll)> sub = [](ll x){
        return x - x;
    };
    function<ll(ll)> div = [](ll x){
        return x / x;
    };

    function<ll(ll)> funs = {mul, add, sub, div};
    set<ll> visited;
    vector<int> ans;
    bool impossible = false;
    q.push(s);
    while(!q.empty()){
        ll n = q.front();
        q.pop();
        if(n == t){
            break;
        }
        int cnt = 0;
        for(auto f: funs){
            ll next = f(n);
            if(visited.find(next) == visited.end()){
                cnt++;
                visited.insert(next);
            }
        }
        if(cnt == 0){
            impossible = true;
            break;
        }

        

    }

    return 0;
}