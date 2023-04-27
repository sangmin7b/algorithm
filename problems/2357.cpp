#include<bits/stdc++.h>
using namespace std;

template <typename T>  class segment_tree{
    public:
        function<T(T,T)> sum;
        vector<T> arr;
        segment_tree(vector<T>& vec, function<T(T,T)> _sum, T _zero){
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
        // 0-based 
        T query(int start, int end){
            return _query(start+1, end+1, 1, 1, N);
        }
        // 0-based
        void update(int idx, int val){
            _update(N+idx, val);
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
        void _update(int idx, int val){
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
    segment_tree<int> min_tree(nums, [](int a, int b){return min(a,b);}, INT32_MAX);
    segment_tree<int> max_tree(nums, [](int a, int b){return max(a,b);}, INT32_MIN);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        cout << min_tree.query(a-1,b-1) << " " << max_tree.query(a-1, b-1) << "\n";
    }
    return 0;
}