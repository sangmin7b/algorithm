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
    int N, L; cin >> N >> L;
    int A, B; cin >> A >> B;
    vi pos(N), hp(100'001);
    for(auto &x: pos) cin >> x;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        hp[pos[i]] = max(hp[pos[i]], x);
    }
    int now = 0;
    int time = 0;
    while(now < L){
        if(now <= 1e5 && hp[now]){
            time = -1;
            break;
        }
        bool flag = false;
        for(int i = now + 1; i <= now + A + 1 && i <= 1e5; i++){
            if(max(0, i - now - 2) * B < hp[i]){
                flag = true;                
            }
        }
        if(flag){
            for(int i = now + 1; i <= now + A && i <= 1e5; i++){
                hp[i] = max(0, hp[i] - B);
            }
            now++;
            L++;
        }else{
            now+=2;
            L++;
        }
        time++;
    }
    cout << time;
    return 0;
}