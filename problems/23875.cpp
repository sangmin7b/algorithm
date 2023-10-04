// 투포인터
// 소 1마리만 배치해서 처리 가능한 만큼만 들어가있도록 관리
// 구간별로 구간 & 최대값 저장
// 구간이 작아지기 직전에만 pq에 insert하면 됨
// pq : 가장 큰 구간부터 처리 and visit 표시
// visit 확인 빠르게 해야... fenwick 쓰는게..


// -> 아님 - 구간별로 최대 2마리만 배치
// -> 1개 일때, 1개 추가할 때 - 기준으로 큰 것부터 정렬
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

int K, M, N;

vector<pl> patches;
vl nhoj_cows;
vl radius;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> K >> M >> N;
    for(int i=0;i<K;i++){
        int p, t;
        cin >> p >> t;
        patches.push_back({p, t});
    }    
    for(int i=0;i<M;i++){
        int f; cin >> f;
        nhoj_cows.push_back(f);
    }    
    radius = vl(K, 1e9);
    sort(patches.begin(), patches.end());
    sort(nhoj_cows.begin(), nhoj_cows.end());
    set<int, greater<int>> s(nhoj_cows.begin(), nhoj_cows.end()); 
    for(int i=0;i<K;i++){
        auto it = lower_bound(nhoj_cows.begin(), nhoj_cows.end(), patches[i].first);
        if(it != nhoj_cows.end()){
            radius[i] = *it - patches[i].first;
        }
        auto it2 = s.lower_bound(patches[i].first);
        if(it2 != s.end()){
            radius[i] = min(radius[i], patches[i].first - *it2);
        }
    }    
    /*for(int x:radius){
        cout << x << " ";
    }
    cout << "\n";
    */
   priority_queue<pair<ll,pl>> pq;
    ll sum = 0;
    int start = 0, end = 0;
    while(end <= K && start < K){
        if(end < K && (start == end || patches[end].first - patches[start].first < radius[start] + radius[end])){
            sum += patches[end].second;
            end++;
        }else{
            pq.push({sum, {start, end-1}});
            sum -= patches[start].second;
            start++;
        }      
    }
    fenwick_tree<int> valid(K);
    int cnt = 0;
    ll ans = 0;
    while(!pq.empty() && cnt < N){
        sum = pq.top().first;
        pl range = pq.top().second;
        pq.pop();
        if(valid.query(range.first+1, range.second+1) == 0){
            ans += sum;
            cnt++;
            for(int i=range.first;i<=range.second;i++){
                valid.add(i+1, 1);
            }
        }        
    }
    cout << ans << "\n";
    return 0;
}     