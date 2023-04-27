#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll psum[3001];

int main(int argc, const char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> psum[i+1];
        psum[i+1] += psum[i];
    }
    ll ans = 1e13;
    int ans_k = N/2; 
    for(int k=1;k<=N/2;k++){
        for(int i=1;i<=N;i++){
            for(int j=i+k;j<=N;j++){
                if(N < j+k-1){
                    break;
                }
                ll d = abs(psum[j+k-1] -  psum[j-1] - (psum[i+k-1] - psum[i-1]));
                if(d <= ans){
                    ans = d;
                    ans_k = k;
                }
            }
        }
    }
    cout << ans_k << "\n";
    cout << ans;
    return 0;
}     