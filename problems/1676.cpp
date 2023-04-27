#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    int cnt2 = 0, cnt5 = 0;
    for(int i=1;i<=N;i++){
        
        for(int n = i; n%2 == 0; n/=2){
            cnt2++;
        }
        for(int n = i; n%5 == 0; n/=5){
            cnt5++;
        }

    }
    int ans = min(cnt2, cnt5);
    cout << ans;
    return 0;
}