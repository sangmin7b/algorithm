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
class fenwick_tree{
 public:
    vector<T> arr;
    int size;
    fenwick_tree(vector<T> &nums){
        size = get_size(nums.size());
        arr = vector<T>(2 * size + 1, 0);
        for(int i=0;i<nums.size();i++){
            add(i+1, nums[i]);
        }
    }

    fenwick_tree(int n){
        size = get_size(n);
        arr = vector<T>(2 * size + 1, 0);
    }

    void add(int idx, T val){
        while(idx <= 2 * size){
            arr[idx] += val;
            idx += (idx & -idx);
        }
        return;
    }

    void update(int idx, T val){
        add(idx, val - query(idx, idx));
        return;
    }

    T query(int idx){
        T ans = 0;
        while(idx){
            ans += arr[idx];
            idx &= idx - 1;
        }
        return ans;
    }

    T query(int l, int r){
        return query(r) - query(l-1);
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
    vi cnt(1000001, 0);
    fenwick_tree<int> is_active(1000000);
    fenwick_tree<int> active_cnt(1000000);
    int N;
    cin >> N;
    while(N--){
        int t, k; cin >> t >> k;
        if(t == 1){
            cnt[k]++;
            active_cnt.add(k, 1);
            if(cnt[k] == 1){
                is_active.add(k, 1);
            }
        }else{
            cnt[k]--;
            active_cnt.add(k, -1);
            if(cnt[k] == 0){
                is_active.add(k, -1);
            }        
        }
        int lo = 0, hi = 1000000;
        while(lo < hi){
            int mid = (lo + hi + 1) / 2;
            if(is_active.query(mid) == mid){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        cout << active_cnt.query(lo) << "\n";
    }
    return 0;
}     