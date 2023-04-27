#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<int>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int nums[500][500];
int visited[500][500];
int N, M, K, X;

bool is_inside(pi p){
    return 0 <= p.first && p.first < N && 0 <= p.second && p.second < M; 
}

pi find_min_max(pi p){
    int min_v = INT32_MAX;
    int max_v = 0;
    for(pi diff: {pi{1,0},{-1,0},{0,1},{0,-1}}){
        pi next = {p.first + diff.first, p.second + diff.second};
        if(!is_inside(next))
            continue;
        int num = nums[next.first][next.second];
        min_v = min(min_v, num);
        max_v = max(max_v, num);
    }
    return {min_v, max_v};
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K >> X;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> nums[i][j];
            visited[i][j] = 0;
        }
    }
    if(K == N * M){
        cout << 0 << "\n";
        return 0;
    }
    int ans = 0;
    priority_queue<pair<int,pi>> pq;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            pi min_max = find_min_max({i, j});
            pq.push({min_max.second - nums[i][j], {i,j}});
            ans = max(ans, min_max.second - nums[i][j]);
        }
    }
    bool ok = true;
    int cnt = 0;
    while(!pq.empty() && cnt < K){
        auto t = pq.top();
        pq.pop();
        pi p = t.second;
        if(visited[p.first][p.second])
            continue;
        visited[p.first][p.second] = 1;
        pi min_max = find_min_max(p);
        ans = min(X - min_max.first, t.first);
        if(X - min_max.first < t.first){
            cnt++;
            nums[p.first][p.second] = X;
            for(pi diff: {pi{1,0},{-1,0},{0,1},{0,-1}}){
                pi next = {p.first + diff.first, p.second + diff.second};
                if(!is_inside(next))
                    continue;
                pq.push({X - nums[next.first][next.second], next});
            }
        }else{
            break;
        }
    }
    cout << ans;
    return 0;
}