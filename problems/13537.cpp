#include<bits/stdc++.h>

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

struct query{
    int i, j, k, idx;
};

bool cmp(query &a, query &b){
    return a.k < b.k;
};

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vi nums(N);
    for(auto &x: nums) cin >> x;
    priority_queue<pi> nums_idx;
    for(int i = 0; i < N; i++){
        nums_idx.push({nums[i], i + 1});
    }
    int M; cin >> M;
    priority_queue<query, vector<query>, decltype(&cmp)> q(cmp);
    for(int t = 0; t < M; t++){
        int i, j, k; cin >> i >> j >> k;
        q.push({i, j, k, t});
    }
    fenwick_tree tree(N);
    vi ans(M);
    while(!q.empty()){
        auto [i, j, k, t] = q.top(); q.pop();
        while(!nums_idx.empty() && nums_idx.top().first > k){
            tree.add(nums_idx.top().second, 1);
            nums_idx.pop();
        }
        ans[t] = tree.query(i, j);
    }  
    for(auto x: ans){
        cout << x << "\n";
    } 
    return 0;
}     