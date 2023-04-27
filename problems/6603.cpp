#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vi v;
vi nums;
int K;
void print_comb(int step, int idx){
    if(step == 6){
        for(int x: v){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    while(idx < K){
        v[step] = nums[idx];
        print_comb(step+1, idx+1);
        idx++;
    }
}

void solve(){
    nums = vi(K,0);
    v = vi(6,0);
    for(int i=0;i<K;i++){
        cin >> nums[i];
    }
    print_comb(0, 0);
    cout << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(1){
        cin >> K;
        if(K == 0){
            break;
        }
        solve();
    }
    return 0;
}     