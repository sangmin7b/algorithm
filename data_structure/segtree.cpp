#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

template <class T> 
class segment_tree{
 public:
    int N;
    function<T(T,T)> f;
    vector<T> arr;
    segment_tree(vector<T>& vec, T identity, function<T(T,T)> f){
        this->f = f;
        this->identity = identity;
        N = get_N(vec.size());
        arr = vector<T> (2*N, identity);
        for(int i=0;i<vec.size();i++){
            arr[N+i] = vec[i];
        }
        for(int i=N-1;i>0;i--){
            arr[i] = f(arr[i*2],arr[i*2+1]);
        }
    };

    segment_tree(int n, T identity, function<T(T,T)> f){
        this->f = f;
        this->identity = identity;
        this->N = get_N(n);
        arr = vector<T> (2*N, identity);
        for(int i=N-1;i>0;i--){
            arr[i] = f(arr[i*2],arr[i*2+1]);
        }
    };

    T query(int l, int r){
        return query({l, r}, 1, {1, N});
    }

    T query(pi query_range, int idx, pi tree_range){
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

    void update(int idx, T val){
        idx += N - 1;
        arr[idx] = val;
        idx = idx / 2;
        while(idx > 0){
            arr[idx] = f(arr[idx*2], arr[idx*2+1]); 
            idx = idx / 2;
        }
    }

    T get(int idx){
        return arr[idx + N - 1];
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
    int N, M;
    cin >> N >> M;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }

    segment_tree<int> min_tree(nums, INT32_MAX, 
        [](int a, int b){return min(a,b);});
    segment_tree<int> max_tree(nums, INT32_MIN, 
        [](int a, int b){return max(a,b);});
    segment_tree<int> sum_tree(nums, 0, 
        [](int a, int b){return a + b;});
    
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