#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int,vector<int>,greater<int>> pq; 
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    int cnt = 0;
    while(pq.size()>1){
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        cnt += a + b;
        pq.push(a+b);
    }
    cout << cnt;
    return 0;
}