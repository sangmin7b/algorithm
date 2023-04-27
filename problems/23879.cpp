#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    int N; cin >> N;
    vector<int> p(N, 0);
    vector<int> t(N, 0);
    vector<int> d(N, 0);
    for(int i=0;i<N;i++){
        cin >> p[i];
    }
    for(int i=0;i<N;i++){
        cin >> t[i];
    }
    for(int i=0;i<N;i++){
        d[i] = p[i] - t[i];
    }
    int prev = 0;
    int ans = 0;
    for(int i=0;i<N;i++){
        if(prev > 0){
            if(d[i] > prev){
                ans += d[i] - prev;
            }
            if(d[i] < 0){
                ans += abs(d[i]);
            }
        }else if(prev < 0){
            if(d[i] < prev){
                ans += prev - d[i];
            }
            if(d[i] > 0){
                ans += abs(d[i]);
            }
        }else{
            ans += abs(d[i]);
        }
        prev = d[i];
    }
    cout << ans;

    return 0;
}
