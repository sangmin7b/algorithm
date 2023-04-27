#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int N, K;
    cin >> N >> K;
    vector<int> dist(100001, -1);
    queue<int> q;
    q.push(N);
    dist[N] = 0;
    while(1){
        int now = q.front();
        q.pop();
        if(now == K){
            break;
        }
        int next[3] = {now-1, now+1, 2*now};
        for(int n: next){
            if(0 <= n && n <= 100000 && dist[n] == -1){
                dist[n] = dist[now] + 1;
                q.push(n);
            }
        }
    }
    int ans = dist[K];
    cout << ans;
    return 0;
}