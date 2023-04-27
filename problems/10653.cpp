#include<bits/stdc++.h>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

const int inf = 123456890;

int dist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<pii> points(N);
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }
    vvi memo(N, vi(K+1,inf));
    memo[N-1][0] = 0;
    memo[N-2][0] = dist(points[N-2],points[N-1]);
    for(int i=N-3;i>=0;i--){
        memo[i][0] = memo[i+1][0] + dist(points[i],points[i+1]);
        for(int j=1;j<=K;j++){
            memo[i][j] = memo[i+1][j] + dist(points[i],points[i+1]);
            for(int k=1;k<=j && i+k+1<N;k++){
                memo[i][j] = min(memo[i][j], memo[i+1+k][j-k] + dist(points[i],points[i+1+k]));
            }
        }
    }
    int ans = inf;
    for(int i=0;i<=K;i++){
        ans = min(ans, memo[0][i]);
    }
    cout << ans;
    return 0;
}