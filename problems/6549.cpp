#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

template <typename T> class segment_tree{
    public:
        function<T(T,T)> f;
        vector<T> arr;
        segment_tree(vector<T>& vec, T identity, function<T(T,T)> f){
            this->f = f;
            this->identity = identity;
            N = get_N(vec.size());
            arr = vector<T> (2*N, identity);
            for(int i=0;i<vec.size();i++){
                arr[N-1+i] = vec[i];
            }
            for(int i=N-2;i>=0;i--){
                arr[i] = f(arr[i*2+1],arr[i*2+2]);
            }
        };
        
        T query(int l, int r){
            return query({l, r}, 0, {0, N-1});
        }

        T query(pii query_range, int idx, pii tree_range){
            if(query_range.first <= tree_range.first && tree_range.second <= query_range.second){
                return arr[idx];
            }
            if(query_range.second < tree_range.first || tree_range.second < query_range.first){
                return identity;
            }
            int mid = (tree_range.first + tree_range.second) / 2;
            return f(query(query_range, 2*idx+1, {tree_range.first, mid}), query(query_range, 2*idx+2, {mid+1, tree_range.second}));
        }

        void update(int idx, T val){
            idx += N - 1;
            arr[idx] = val;
            idx = (idx - 1) / 2;
            while(idx >= 0){
                arr[idx] = f(arr[idx*2+1], arr[idx*2+2]); 
                if(idx == 0)
                    break;
                idx = (idx - 1) / 2;
            }
        }

    private:
        int N;
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
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }

    segment_tree<int> min_tree(nums, INT32_MAX, [](int a, int b){return min(a,b);});
    segment_tree<int> max_tree(nums, INT32_MIN, [](int a, int b){return max(a,b);});
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        cout << min_tree.query(a,b) << " " << max_tree.query(a, b) << "\n";
    }
    return 0;
}