#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

class segment_tree{
public:
    int N;
    vector<ll> arr;
    vector<ll> lazy;
    segment_tree(vector<ll>& vec){
        N = get_N(vec.size());
        arr = vector<ll> (2 * N, 0);
        lazy = vector<ll> (2 * N, 0);
        for(int i = 0; i < vec.size(); i++){
            arr[N + i] = vec[i];
        }
        for(int i = N - 1; i > 0; i--){
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    };

    segment_tree(int n){
        this->N = get_N(n);
        arr = vector<ll> (2 * N, 0);
        lazy = vector<ll> (2 * N, 0);
        for(int i=N-1;i>0;i--){
            arr[i] = arr[i*2] + arr[i*2+1];
        }
    };

    ll query(int l, int r){
        return query({l, r}, 1, {1, N});
    }

    ll query(pi query_range, int idx, pi tree_range){
        update_lazy(idx, tree_range);
        if(query_range.first <= tree_range.first 
            && tree_range.second <= query_range.second
        ){
            return arr[idx];
        }
        if(query_range.second < tree_range.first 
            || tree_range.second < query_range.first
        ){
            return 0;
        }
        int mid = (tree_range.first + tree_range.second) / 2;
        return query(query_range, 2*idx, {tree_range.first, mid}) + query(query_range, 2*idx+1, {mid+1, tree_range.second});
    }

    void update(pi query_range, ll diff){
        update(query_range, diff, 1, {1, N});
        return;
    }

    void update(pi query_range, ll diff, int idx, pi tree_range){
        update_lazy(idx, tree_range);
        if(query_range.first <= tree_range.first 
            && tree_range.second <= query_range.second
        ){
            lazy[idx] += diff;
            update_lazy(idx, tree_range);
            return;        
        }
        if(query_range.second < tree_range.first 
            || tree_range.second < query_range.first
        ){
            return;
        }
        int mid = (tree_range.first + tree_range.second) / 2;
        update(query_range, diff, 2 * idx, {tree_range.first, mid});
        update(query_range, diff, 2 * idx + 1, {mid + 1, tree_range.second});
        arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
    }

    void update_lazy(int idx, pi tree_range){
        if(lazy[idx] == 0) return;
        arr[idx] += (tree_range.second - tree_range.first + 1) * lazy[idx];
        if(tree_range.second != tree_range.first){
            int mid = (tree_range.first + tree_range.second) / 2;
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

private:
    int get_N(int n){
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
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> nums(N,0);
    for(int i = 0; i < N;i++){
        cin >> nums[i];
    }
    segment_tree sum_tree(nums);    
    for(int i = 0; i < M + K; i++){
        ll q, a, b, c;
        cin >> q;
        if(q == 1){
            cin >> a >> b >> c;
            sum_tree.update({a, b}, c);
        }else{
            cin >> a >> b;
            cout << sum_tree.query(a, b) << "\n";
        }
    }
    return 0;
}