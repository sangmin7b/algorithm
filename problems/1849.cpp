#include<bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;

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
                arr[N+i] = vec[i];
            }
            for(int i=N-1;i>0;i--){
                arr[i] = f(arr[i*2],arr[i*2+1]);
            }
        };
        
        T query(int l, int r){
            return query({l, r}, 1, {1, N});
        }

        T query(pii query_range, int idx, pii tree_range){
            if(query_range.first <= tree_range.first && tree_range.second <= query_range.second){
                return arr[idx];
            }
            if(query_range.second < tree_range.first || tree_range.second < query_range.first){
                return identity;
            }
            int mid = (tree_range.first + tree_range.second) / 2;
            return f(query(query_range, 2*idx, {tree_range.first, mid}), query(query_range, 2*idx+1, {mid+1, tree_range.second}));
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
    int N;
    cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    vi idx(N,1);
    segment_tree<int> seg(idx, 0, [](int a, int b){return a+b;});
    auto find = [&](int x){
        int lo = 0, hi = N + 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(seg.query(1, mid) < x){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        return hi;
    };
    vi ans(N,0);
    for(int i=0;i<N;i++){
        int idx = find(nums[i] + 1);
        ans[idx - 1] = i + 1;
        seg.update(idx, 0);
    }
    for(int i: ans){
        cout << i << "\n";
    }
    return 0;
}