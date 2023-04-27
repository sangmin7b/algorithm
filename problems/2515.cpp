#include<bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using ll = long long;
ll dp[300000];

int main(int argc, char const *argv[]){
    int N, S;
    cin >> N >> S;
    vector<pii> pictures;
    for(int i=0;i<N;i++){
        int h, v;
        cin >> h >> v;
        pictures.push_back({h, v});
    }
    vector<int> heights;
    sort(pictures.begin(), pictures.end());
    transform(pictures.begin(), pictures.end(), back_inserter(heights),[](pii p){return p.first;});
    ll max_next = 0;
    for(int x = N-1; x>=0; x--){
        int h = pictures[x].first;
        int v = pictures[x].second;
        int start = upper_bound(heights.begin(), heights.end(), h+S-1) - heights.begin(); 
        int end =  lower_bound(heights.begin(), heights.end(), h+3*S-1) - heights.begin(); 
        int next = upper_bound(heights.begin(), heights.end(), h+S-1) - heights.begin(); 
        if(next < N){
            max_next = max(max_next, dp[next]);
        }
        ll max_next = *max_element(dp + start, dp + end + 1);
        dp[x] = v + max_next;
    }
    int ans = *max_element(dp,dp+N);
   
    cout << ans;
    return 0;
}
