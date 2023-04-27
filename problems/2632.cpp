#include<bits/stdc++.h>
using namespace std;

void make_cnt(vector<int>& v, vector<int>& cnt, int target){
    for(int i=0;i<v.size();i++){
        int sum = 0;
        for(int j=0;j<v.size()-1;j++){
            int idx = (i + j) % v.size();
            sum += v[idx];
            if(sum > target){
                break;
            }
            cnt[sum]++;
        }
    }
    int total = 0;
    for(int i=0;i<v.size();i++){
        total += v[i];
    }
    if(total <= target){
        cnt[total]++;
    }
    return;
}

int main(int argc, char* const argv[]){
    int target;
    cin >> target;
    int M, N;
    cin >> M >> N;
    vector<int> A, B;
    vector<int> cnt_A(target + 1, 0);
    vector<int> cnt_B(target + 1, 0);

    for(int i=0;i<M;i++){
        int x; cin >> x;
        A.push_back(x);
    }

    for(int i=0;i<N;i++){
        int x; cin >> x;
        B.push_back(x);
    }

    make_cnt(A, cnt_A, target);
    make_cnt(B, cnt_B, target);
    
    int ans = 0;
    for(int i=0;i<=target;i++){
        ans += cnt_A[i] * cnt_B[target - i];
    }
    ans += cnt_A[target];
    ans += cnt_B[target];
    cout << ans;

    return 0;
}