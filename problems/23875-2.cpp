// -> 아님 - 구간별로 최대 2마리만 배치
// -> 1개 일때, 1개 추가할 때 - 기준으로 큰 것부터 정렬
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int K, M, N;

vector<pl> patches;
vl nhoj_cows;
vl radius;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> K >> M >> N;
    for(int i=0;i<K;i++){
        int p, t;
        cin >> p >> t;
        patches.push_back({p, t});
    }    
    for(int i=0;i<M;i++){
        int f; cin >> f;
        nhoj_cows.push_back(f);
    }    
    radius = vl(K, 1e9);
    sort(patches.begin(), patches.end());
    sort(nhoj_cows.begin(), nhoj_cows.end());

    

    priority_queue<ll> pq;

    
    return 0;
}     