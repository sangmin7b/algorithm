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
    int N;
    cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    int lo = 0;
    int hi = N;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        bool ok = false;
        int cnt = 0;
        for(int i=0;i<N;i++){
            if(nums[i] < mid){
                cnt = 0;
                continue;
            }
            if(++cnt == mid){
                ok = true;
                break;
            }
        }
        if(ok){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
    return 0;
}     