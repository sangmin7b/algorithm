#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

class segment_tree{
 public:
    int N;
    vector<long long> arr;
    segment_tree(vector<long long>& vec){
        N = get_N(vec.size());
        arr = vector<long long> (2 * N, 0);
        for(int i = 0; i < vec.size(); i++){
            arr[N+i] = vec[i];
        }
        for(int i = N - 1; i > 0; i--){
            arr[i] = max(arr[i * 2],arr[i * 2 + 1]);
        }
    };

    segment_tree(int n){
        this->N = get_N(n);
        arr = vector<long long> (2 * N, 0);
        for(int i = N - 1; i > 0; i--){
            arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
        }
    };

    long long query(int l, int r){
        return query({l, r}, 1, {1, N});
    }

    long long query(pi query_range, int idx, pi tree_range){
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
        return max(query(query_range, 2*idx, {tree_range.first, mid}), 
            query(query_range, 2*idx+1, {mid+1, tree_range.second}));
    }

    void update(int idx, long long val){
        idx += N - 1;
        arr[idx] = val;
        idx = idx / 2;
        while(idx > 0){
            arr[idx] = max(arr[idx * 2], arr[idx * 2 + 1]); 
            idx = idx / 2;
        }
    }

    long long get(int idx){
        return arr[idx + N - 1];
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
    int N, M;
    cin >> N >> M;
    vector<long long> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    segment_tree max_tree(nums);    
    for(int i=0;i<M;i++){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0){
            max_tree.update(a, b);
        }else{
            cout << max_tree.query(a,b) << "\n";
        }
    }
    return 0;
}