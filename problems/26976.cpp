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
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    int cnt = 0;
    vi ans(N,-1);
    int prev[2] = {-1, -1};
    for(int i=0;i<N;i++){
        int breed = s[i] == 'G' ? 0 : 1;
        if(prev[breed] != -1 && i <= prev[breed] + K){
            continue;
        }
        cnt++;
        int idx = i + K;
        idx = min(N-1, idx);
        if(ans[idx] == -1){
            ans[idx] = breed;
        }else{
            while(ans[idx] != -1){
                idx--;
            }
            ans[idx] = breed; 
        }
        prev[breed] = idx;
    }
    cout << cnt << "\n";
    for(int x: ans){
        switch (x){
        case -1:
            cout << ".";
            break;
        case 0:
            cout << "G";
            break;
        case 1:
            cout << "H";
            break;
        }
    }
    cout << "\n";
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