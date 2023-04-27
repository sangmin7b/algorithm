#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<int>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll nums[500][500];
int visited[500][500];
ll N, M, K, X;

bool is_inside(pi p){
    return 0 <= p.first && p.first < N && 0 <= p.second && p.second < M; 
}

pl find_min_max(pi p){
    ll min_v = X;
    ll max_v = 0;
    for(pi diff: {pi{1,0},{-1,0},{0,1},{0,-1}}){
        pi next = {p.first + diff.first, p.second + diff.second};
        if(!is_inside(next))
            continue;
        ll num = nums[next.first][next.second];
        min_v = min(min_v, num);
        max_v = max(max_v, num);
    }
    return {min_v, max_v};
}

ll find(){
    int cnt = 0;
    priority_queue<pair<ll,pi>> pq;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            pl min_max = find_min_max({i, j});
            pq.push({min_max.second - nums[i][j], {i,j}});
        }
    }
    ll ans = pq.top().first;
    while(!pq.empty() && cnt < K){
        auto t = pq.top();
        pq.pop();
        pi p = t.second;
        ans = min(ans, t.first);
        if(visited[p.first][p.second])
            continue;
        visited[p.first][p.second] = 1;
        pl min_max = find_min_max(p);
        cnt++;
        for(pi diff: {pi{1,0},{-1,0},{0,1},{0,-1}}){
            pi next = {p.first + diff.first, p.second + diff.second};
            if(!is_inside(next))
                continue;
            pq.push({X - nums[next.first][next.second], next});
        }
    }
    while(!pq.empty() && visited[pq.top().second.first][pq.top().second.second]){
        pq.pop();
    }
    if(pq.empty()){
        return 0;
    }else{
        ans = min(ans, pq.top().first);
        return max(ans, (ll)0);
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K >> X;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> nums[i][j];
        }
    }
    cout << find();
    return 0;
}