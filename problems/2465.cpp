#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
using vi = vector<int>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    rope<int> r;
    for(int i=0;i<N;i++){
        int rank; cin >> rank;
        r.insert(rank, i);
    }
    vi ans(N);
    for(int i=0;i<N;i++){
        ans[r[i]] = i; 
    }    
    for(int i=0;i<N;i++){
        cout << nums[ans[i]] << "\n";
    }    
    return 0;
}     