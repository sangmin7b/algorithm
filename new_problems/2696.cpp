#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void solve(){
    int N; cin >> N;
    priority_queue<int, vi> max_heap;
    priority_queue<int, vi, greater<int>> min_heap;
    // min heap size > max heap size

    // 0 ~ 18 
    // 38
    // 0 2 4 6 8 10 12 14 16 18
    // 20 22                 38 
    cout << N / 2 + 1 << "\n";
    int mid; cin >> mid;
    cout << mid << " ";    
    max_heap.push(mid);
    for(int i=1;i<N;i++){
        int x; cin >> x;
        if(max_heap.top() < x){
            min_heap.push(x);
        }else{
            max_heap.push(x);
        }
        if(i % 2 == 0){
            while(max_heap.size() <= min_heap.size()){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            while(min_heap.size() < max_heap.size() - 1){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            cout << max_heap.top();
            if(i % 20 == 18){
                cout << "\n";
            }else{
                cout << " ";
            }
        }
    }
    if((N / 2 + 1) % 10 != 0){
        cout << "\n";
    }
}   

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}