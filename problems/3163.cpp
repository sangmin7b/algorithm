#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void soanse(){
    int N, L, K;
    cin >> N >> L >> K;
    vector<pi> v(N);
    vector<pi> ans;
    for(int i=0;i<N;i++){
        int id, x;
        cin >> x >> id;
        v[i] = {x, id};
    } 
    int lcnt = 0;
    for(int i=0;i<N;i++){
        if(v[i].second < 0){
            ans.push_back({v[i].first, v[lcnt].second});
            lcnt++;
        }
    }
    for(int i=N-1;0<=i;i--){
        if(0 < v[i].second){
            ans.push_back({L - v[i].first, v[N-1-ans.size()+lcnt].second});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[K-1].second << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        soanse();
    }
    return 0;
}