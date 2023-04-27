#include<bits/stdc++.h>
using namespace std;

template <typename T>  class segment_tree{
    public:
        function<T(T,T)> sum;
        vector<T> arr;
        segment_tree(vector<T>& vec, T _zero, function<T(T,T)> _sum){
            sum = _sum;
            zero = _zero;
            N = get_N(vec.size());
            arr = vector<T> (2*N, zero);
            for(int i=0;i<vec.size();i++){
                arr[N+i] = vec[i];
            }
            for(int i=N-1;i>0;i--){
                arr[i] = sum(arr[i*2],arr[i*2+1]);
            }
        };
        // 1-based 
        T query(int start, int end){
            return _query(start, end, 1, 1, N);
        }
        // 1-based
        void update(int idx, T val){
            _update(N-1+idx, val);
        }
    private:
        int N;
        T zero;
        T _query(int start, int end, int idx, int l, int r){
            if(start<=l && r <= end){
                return arr[idx];
            }
            if(end < l || r < start){
                return zero;
            }
            int mid = (l+r) / 2;
            return sum(_query(start, end, 2*idx, l, mid), _query(start, end, 2*idx+1, mid+1, r));
        }
        void _update(int idx, T val){
            arr[idx] = val;
            idx /= 2;
            while(idx > 0){
                arr[idx] = sum(arr[idx*2], arr[idx*2+1]); 
                idx /= 2;
            }
        }
        int get_N(int _N){
            int i = 1;
            while(i < _N){
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