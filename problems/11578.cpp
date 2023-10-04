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
    int N, M; cin >> N >> M;
    vi student(M, 0);
    for(int i = 0; i < M; i++){
        int n; cin >> n;
        for(int j = 0; j < n; j++){
            int x; cin >> x; x--;
            student[i] |= (1 << x);
        }
    }
    int all_solved = (1 << N) - 1;
    bool is_possible = false;
    int ans = M;
    for(int i = 1; i <= (1 << (M + 1)); i++){
        int solved = 0;
        int cnt = 0;
        for(int j = 0; j < M; j++){
            if(i & (1 << j)){
                solved |= student[j];
                cnt++;
            }
        }
        if(solved == all_solved){
            is_possible = true;
            ans = min(ans, cnt);
        }
    }
    if(is_possible){
        cout << ans;
    }else{
        cout << -1;
    }

    return 0;
}     