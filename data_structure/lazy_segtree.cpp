#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

template <class T> 
class segment_tree{
public:
    int N;
    function<T(T,T)> f;
    vector<T> arr;
    vector<T> lazy;
    segment_tree(vector<T>& vec, T identity, function<T(T,T)> f){
        this->f = f;
        this->identity = identity;
        N = get_N(vec.size());
        arr = vector<T> (2 * N, identity);
        lazy = vector<T> (2 * N, identity);
        for(int i = 0; i < vec.size(); i++){
            arr[N + i] = vec[i];
        }
        for(int i = N - 1; i > 0; i--){
            arr[i] = f(arr[i * 2],arr[i * 2 + 1]);
        }
    };

    segment_tree(int n, T identity, function<T(T,T)> f){
        this->f = f;
        this->identity = identity;
        this->N = get_N(n);
        arr = vector<T> (2 * N, identity);
        lazy = vector<T> (2 * N, identity);
        for(int i=N-1;i>0;i--){
            arr[i] = f(arr[i*2],arr[i*2+1]);
        }
    };

    T query(int l, int r){
        return query({l, r}, 1, {1, N});
    }

    T query(pi query_range, int idx, pi tree_range){
        update_lazy(idx, tree_range);
        if(query_range.first <= tree_range.first 
            && tree_range.second <= query_range.second
        ){
            return arr[idx];
        }
        if(query_range.second < tree_range.first 
            || tree_range.second < query_range.first
        ){
            return identity;
        }
        int mid = (tree_range.first + tree_range.second) / 2;
        return f(query(query_range, 2*idx, {tree_range.first, mid}), 
            query(query_range, 2*idx+1, {mid+1, tree_range.second}));
    }

    void update(pi query_range, T diff){
        update(query_range, diff, 1, {1, N});
        return;
    }

    void update(pi query_range, T diff, int idx, pi tree_range){
        update_lazy(idx, tree_range);
        if(query_range.first <= tree_range.first 
            && tree_range.second <= query_range.second
        ){
            lazy[idx] = f(lazy[idx], diff);
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
        arr[idx] = f(arr[idx * 2], arr[idx * 2 + 1]);
    }

    void update_lazy(int idx, pi tree_range){
        if(lazy[idx] == identity) return;
        arr[idx] = f(arr[idx], apply_n(lazy[idx], tree_range.second - tree_range.first + 1));
        if(tree_range.second != tree_range.first){
            int mid = (tree_range.first + tree_range.second) / 2;
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    T apply_n(T x, int n){
        T result = identity;
        for(int i = 0; i < n; i++){
            result = f(result, x);
        }
        return result;
    }

private:
    T identity;
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
    segment_tree<ll> sum_tree(nums, 0, 
        [](ll a, ll b){return a + b;});
    
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