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
    fenwick_tree(int n){
        size = get_size(n);
        arr = vector<T>(2 * size + 1, 0);
    }

    void add(int idx, T val){
        while(idx <= 2 * size){
            arr[idx] ^= val;
            idx += (idx & -idx);
        }
        return;
    }

    void update(int idx, T val){
        add(idx, val ^ query(idx, idx));
        return;
    }

    T query(int idx){
        T ans = 0;
        while(idx){
            ans ^= arr[idx];
            idx &= idx - 1;
        }
        return ans;
    }

    T query(int l, int r){
        return query(r) ^ query(l-1);
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
    cin >> N;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    fenwick_tree<int> tree(N);
    cin >> M;
    for(int i=0;i<M;i++){
        int t; cin >> t;
        if(t == 1){
            int a, b, c; cin >> a >> b >> c;
            a++; b++;
            tree.add(a, c);
            tree.add(b+1, c);
        }else{
            int a; cin >> a;
            cout << (tree.query(a+1) ^ nums[a]) << "\n";
        }
    }
    return 0;
}     