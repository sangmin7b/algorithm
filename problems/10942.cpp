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
    int N, M;
    cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    vi cnt_odd(N,0);
    vi cnt_even(N,0);
    for(int i=1;i<N-1;i++){
        int left = i - 1;
        int right = i + 1;
        while(left >= 0 && right < N && nums[left] == nums[right]){
            cnt_odd[i]++;
            left--;
            right++;
        }
    }
    for(int i=0;i<N-1;i++){
        int left = i;
        int right = i + 1;
        while(left >= 0 && right < N && nums[left] == nums[right]){
            cnt_even[i]++;
            left--;
            right++;
        }
    }
    cin >> M;
    for(int i=0;i<M;i++){
        int S, E;
        cin >> S >> E;
        S--; E--;
        int length = E - S + 1;
        int mid = (S + E) / 2;
        int ans = 0;
        if((length & 1) == 0){
            ans = (cnt_even[mid] >= length / 2) ? 1 : 0;         
        }else{
            ans = (cnt_odd[mid] >= length / 2) ? 1 : 0;         
        }
        cout << ans << "\n";
    }
    return 0;
}