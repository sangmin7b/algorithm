#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

class fenwick_tree{
 public:
    vector<ll> arr;
    int size;
    fenwick_tree(vector<ll> &nums){
        size = get_size(nums.size());
        arr = vector<ll>(2 * size + 1, 0);
        for(int i=0;i<nums.size();i++){
            add(i+1, nums[i]);
        }
    }
    
    fenwick_tree(int n){
        size = get_size(n);
        arr = vector<ll>(2 * size + 1, 0);
    }

    void add(int idx, ll val){
        while(idx <= 2 * size){
            arr[idx] += val;
            idx += (idx & -idx);
        }
        return;
    }

    void update(int idx, ll val){
        add(idx, val - query(idx, idx));
        return;
    }

    ll query(int idx){
        ll ans = 0;
        while(idx){
            ans += arr[idx];
            idx &= idx - 1;
        }
        return ans;
    }

    ll query(int l, int r){
        return query(r) - query(l-1);
    }

 private:
    int get_size(int n){
        int i = 1;
        while(i < n){
            i *= 2;
        }
        return i;
    }
};

int main(int argc, const char** argv) {
    int N, M;
    cin >> N >> M;
    vector<ll> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    fenwick_tree sum_tree(nums);
    for(int i=0;i<M;i++){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0){
            sum_tree.update(a, b);
        }else{
            cout << sum_tree.query(a,b) << "\n";
        }
    }
    return 0;
}
