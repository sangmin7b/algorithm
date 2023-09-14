#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

class segment_tree{
 public:
    int N;
    vvi arr;
    segment_tree(vvi& vec){
        N = 1 << (int)ceil(log2(vec.size()));
        arr = vvi(2 * N);
        for(int i=0;i<vec.size();i++){
            arr[N+i] = vec[i];
        }
        for(int i=N-1;i>0;i--){
            arr[i] = merge(arr[i*2], arr[i*2+1]);
        }
    };
    int query(int l, int r, int k){
        return query({l, r}, 1, {1, N}, k);
    }

    int query(pi query_range, int idx, pi tree_range, int k){
        if(query_range.first <= tree_range.first 
            && tree_range.second <= query_range.second
        ){
            return arr[idx].size() - (upper_bound(arr[idx].begin(), arr[idx].end(), k) - arr[idx].begin());
        }
        if(query_range.second < tree_range.first 
            || tree_range.second < query_range.first
        ){
            return 0;
        }
        int mid = (tree_range.first + tree_range.second) / 2;
        return query(query_range, 2*idx, {tree_range.first, mid}, k) + 
            query(query_range, 2*idx+1, {mid+1, tree_range.second}, k);
    }

 private:
    vi merge(vi &a, vi &b){
        vi c; 
        int ai = 0, bi = 0;
        while(ai < a.size() && bi < b.size()){
            if(a[ai] < b[bi]){
               c.push_back(a[ai]);
               ai++; 
            }else{
                c.push_back(b[bi]);
                bi++;
            }
        }
        while(ai < a.size()){
            c.push_back(a[ai]);
            ai++; 
        }
        while(bi < b.size()){
            c.push_back(b[bi]);
            bi++;            
        }
        return c;
    };
};

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vvi nums(N);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        nums[i].push_back(x);
    }
    auto merge = [](vi a, vi b){
        vi c; 
        int ai = 0, bi = 0;
        while(ai < a.size() && bi < b.size()){
            if(a[ai] < b[bi]){
               c.push_back(a[ai]);
               ai++; 
            }else{
                c.push_back(b[bi]);
                bi++;
            }
        }
        while(ai < a.size()){
            c.push_back(a[ai]);
            ai++; 
        }
        while(bi < b.size()){
            c.push_back(b[bi]);
            bi++;            
        }
        return c;
    };
    segment_tree merge_sort_tree(nums);
    int M; cin >> M;
    int ans = 0;
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        a ^= ans; b ^= ans; c ^= ans;
        ans = merge_sort_tree.query(a, b, c);
        cout << ans << "\n";
    }
    return 0;
}     