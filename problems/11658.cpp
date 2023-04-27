#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

template<class T>
class fenwick_tree_2d{
 public:
    vector<vector<T>> arr;
    vector<vector<T>> node;
    pi size;
    fenwick_tree_2d(vector<vector<T>> &nums){
        size.first = get_size(nums.size());
        size.second = get_size(nums[0].size());
        arr = vector<vector<T>>(nums.size()+1, 
            vector<T>(nums[0].size() + 1, 0));
        node = vector<vector<T>>(2 * size.first + 1, 
            vector<T>(2 * size.second + 1, 0));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[0].size();j++){
                add(i+1, j+1,nums[i][j]);
            }
        }
    }

    void add(int r, int c, T val){
        arr[r][c] += val;
        while(r <= 2 * size.first){
            int c2 = c; 
            while(c2 <= 2 * size.second){
                node[r][c2] += val;
                c2 += (c2 & -c2);
            }
            r += (r & -r);
        }
        return;
    }

    void update(int r, int c, T val){
        add(r, c, val - arr[r][c]);
        return;
    }

    T query(int r, int c){
        T ans = 0;
        while(r){
            int c2 = c;
            while(c2){
                ans += node[r][c2];
                c2 &= c2 - 1;
            }
            r &= r - 1;
        }
        return ans;
    }

    T query(pi start, pi end){
        return query(end.first, end.second) - query(end.first, start.second - 1) - query(start.first - 1, end.second) + query(start.first - 1, start.second - 1);
    }

 private:
    int get_size(int n){
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
    int N, M;
    cin >> N >> M;
    vvi nums(N,vi(N, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> nums[i][j];
        }
    }
    fenwick_tree_2d<int> tree(nums);
    for(int i=0;i<M;i++){
        int q; cin >> q;
        if(q == 0){
            int r, c, v;
            cin >> r >> c >> v;
            tree.update(r, c, v);
        }else{
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << tree.query({a, b}, {c, d}) << "\n";
        }
    }
    return 0;
}     