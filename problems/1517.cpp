#include <algorithm>
#include<bits/stdc++.h>
#include <mutex>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;


template <class T> class segment_tree{
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

vi nums;
vi unums;
vi cnt;
int get_idx(int x){
    return lower_bound(unums.begin(), unums.end(), x) - unums.begin();
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    nums = vi(N,0);
    unums = vi(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
        unums[i] = nums[i];
    }
    sort(unums.begin(), unums.end());
    unums.erase(unique(unums.begin(), unums.end()),unums.end());
    cnt = vi(unums.size(), 0);
    for(int x: nums){
        cnt[get_idx(x)]++;
    }
    segment_tree<int> cnt_unused(cnt, 0, [](int a, int b){return a+b;});
    ll ans = 0;
    for(int i=0;i<N;i++){
        int idx = get_idx(nums[i]);
        ans += cnt_unused.query(1, idx);
        cnt[idx]--;
        cnt_unused.update(idx+1, cnt[idx]);
    }
    cout << ans;
    return 0;
}     