#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

struct group{
    int start, end, size;
};

auto cmp = [](group &a, group &b){
    return a.end < b.end;
};

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int K, N, C; cin >> K >> N >> C;
    vector<group> v;
    for(int i = 0; i < K; i++){
       int s, e, m; cin >> s >> e >> m;
       v.push_back({s, e, m}); 
    }  
    sort(v.begin(), v.end(), cmp);
    multiset<int, greater<int>> s;
    for(int i = 0; i < C; i++){
        s.insert(0);
    }
    int ans = 0;
    for(int i = 0; i < K; i++){
        while(v[i].size){
            auto x = s.lower_bound(v[i].start);
            if(x == s.end()){
                break;
            }
            s.erase(x); s.insert(v[i].end);
            v[i].size--;
            ans++;
        }        
    }
    cout << ans;
    return 0;
}     