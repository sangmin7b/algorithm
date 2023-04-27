#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int cnt[1000001];
int nums[2000000];

void solve(){
    int N; cin >> N;
    ll ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0;i<N;i++){
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    for(int a=1;a<=1000000;a++){
        for(int x=a;x<=1000000;x+=a){
            if(x % a != 0){continue;}
            if((x & a) == 0 && x+a <= 1000000){
                ans += (ll)cnt[x] * cnt[x+a];
            }
            int b = x / a;
            if(b <= 1000){
                continue;
            }
            if((x&b) == 0 && x+b <= 1000000){
                ans += cnt[x] * cnt[x+b];
            }
        }
    }
    cout << ans << "\n";
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