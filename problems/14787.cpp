#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

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
            arr[idx] ^= val;
            idx += (idx & -idx);
        }
        return;
    }

    void update(int idx, ll val){
        add(idx, val ^ query(idx, idx));
        return;
    }

    ll query(int idx){
        ll ans = 0;
        while(idx){
            ans ^= arr[idx];
            idx &= idx - 1;
        }
        return ans;
    }

    ll query(int l, int r){ 
        return query(r) ^ query(l-1);
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

void solve(){
    int Q; cin >> Q;
    vi inputs;
    int cnt = 0;
    for(int i = 0; i < Q; i++){
        string s; cin >> s;
        if(s == "insert"){
            int x; cin >> x;
            inputs.push_back(x);
            cnt++;
        }else{
            int x; cin >> x;
            inputs.push_back(-x);
        }
    }
    fenwick_tree sum_tree(cnt);
    ordered_set order_tree;
    // map idx to rank
    map<int, int> rank;
    vector<pi> nums;
    for(int i = 0; i < Q; i++){
        if(inputs[i] >= 0){
            nums.push_back({inputs[i], i});
        }
    }    
    // 1. query with greater value 2. query that had arrived later comes first
    sort(nums.begin(), nums.end(), greater<pi>());
    for(int i = 0; i < nums.size(); i++){
        rank[nums[i].second] = i + 1;
    }
    int max_rank = 0;
    for(int i = 0; i < Q; i++){
        if(inputs[i] >= 0){
            sum_tree.add(rank[i], inputs[i]);
            order_tree.insert(rank[i]);
            max_rank = max(max_rank, rank[i]);
        }else{
            int x = -inputs[i];
            int idx = 0;            
            if(order_tree.size() < x){
                idx = max_rank;                    
            }else{
                idx = *order_tree.find_by_order(x - 1);            
            }
            cout << sum_tree.query(1, idx) << "\n";           
        }
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}     