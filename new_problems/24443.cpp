#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vi nums;

int kth(vi nums, int k){
    cout << "k : " << k << endl;
    if(nums.size() <= 5){
        for(int j = nums.size() - 1; j > 0; j--){
            for(int i = j - 1; i >= 0; i--){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        for(int x: nums){
            cout << x << " ";
        }
        cout << "\n";
        return nums[k];
    }
    vi tmp;
    for(int i = 0; i < nums.size(); i+=5){
        int end = min((int)nums.size(), i + 6);
        tmp.push_back(kth(vi(nums.begin() + i, nums.begin() + end), (nums.size()) / 2));
    }
    int mid = kth(tmp, tmp.size() / 2);
    if(k == tmp.size() / 2){
        return mid;
    }
    cout << "mid " << mid << "\n";
    int idx = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < mid){
            swap(nums[i], nums[idx++]);
        }
    }
    
    if(k > idx){
        return kth(vi(nums.begin() + idx + 1, nums.end()), k - idx - 1);
    }else{
        return kth(vi(nums.begin(), nums.begin() + idx), k);
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int i, j, k; cin >> i >> j >> k; i--, j--, k--;
            cout << kth(vi(nums.begin() + i, nums.begin() + j + 1), k) << "\n";        
        }else{
            int i, j; cin >> i >> j; i--, j--;
            swap(nums[i], nums[j]);
        }
    }
    return 0;
}       