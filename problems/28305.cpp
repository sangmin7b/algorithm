#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, T;
    cin >> N >> T;
    vi A(N);
    for(int &x : A){
        cin >> x;
    }
    sort(A.begin(), A.end());
    int lo = 1, hi = N;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        priority_queue<int, vi, greater<int>> pq;
        for(int i = 0; i < mid; i++){
            pq.push(1);
        }
        bool ok = true;
        for(int x: A){
            int start_t = pq.top(); pq.pop();
            if(x < start_t){
                ok = false;
                break;
            }
            int end_t = max(start_t + T, x + 1);
            pq.push(end_t);        
        }
        if(ok){
            hi = mid;
        }else{
            lo = mid + 1; 
        }
    }
    cout << lo;    
    return 0;
}     