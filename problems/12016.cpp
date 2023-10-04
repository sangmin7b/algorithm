#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

template<class T>
class fenwick_tree{
 public:
    vector<T> arr;
    int size;
    fenwick_tree(vector<T> &nums){
        size = get_size(nums.size());
        arr = vector<T>(2 * size + 1, 0);
        for(int i=0;i<nums.size();i++){
            add(i+1, nums[i]);
        }
    }
    
    fenwick_tree(int n){
        size = get_size(n);
        arr = vector<T>(2 * size + 1, 0);
    }
    
    void add(int idx, T val){
        while(idx <= 2 * size){
            arr[idx] += val;
            idx += (idx & -idx);
        }
        return;
    }

    void update(int idx, T val){
        add(idx, val - query(idx, idx));
        return;
    }

    T query(int idx){
        T ans = 0;
        while(idx){
            ans += arr[idx];
            idx &= idx - 1;
        }
        return ans;
    }

    T query(int l, int r){
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    fenwick_tree<int> is_active(N);
    for(int i=0;i<N;i++){
        is_active.add(i+1,1);
    }
    vector<pi> processes(N);
    for(int i=0;i<N;i++){
        int x; cin >> x;
        processes[i] = {x, i};
    }
    sort(processes.begin(), processes.end());
    vl ans(N, 0);
    ll clock = 0;
    ll last_t = 0;
    int idx_l = 0, idx_r = 0;
    while(idx_l < N){
        while(idx_r < N && processes[idx_r].first == processes[idx_l].first){
            idx_r++;
        }
        ll p_num = is_active.query(1, N);
        ll t = processes[idx_l].first;
        clock += p_num * (t - last_t - 1);
        for(int i=idx_l;i<idx_r;i++){
            ans[processes[i].second] = clock + is_active.query(1, processes[i].second + 1);
        }
        for(int i=idx_l;i<idx_r;i++){
            is_active.add(processes[i].second + 1, -1);
        }
        clock += p_num;
        last_t = t;
        idx_l = idx_r;
    }
    for(ll x: ans){
        cout << x << "\n";
    }
    return 0;
}     