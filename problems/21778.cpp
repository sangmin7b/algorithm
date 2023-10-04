#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, Q;

struct process{
    ll id, priority, load;
};

bool cmp(process &a, process &b){
    if(a.priority == b.priority){
        return a.id < b.id;    
    }
    return a.priority > b.priority;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> Q >> N;
    vector<process> processes;
    for(int i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        processes.push_back({a, c, b});
    }
    sort(processes.begin(), processes.end(), cmp);    
    while(Q--){
        ll t; cin >> t;
        ll lo = -1e14, hi = 1e14;
        while(lo < hi){
            ll mid = (lo + hi + 1) / 2;
            ll t2 = 0;
            for(auto p : processes){
                if(p.priority < mid || t <= t2){
                    break;
                }
                t2 += min(p.load, p.priority - mid + 1);
            }
            if(t <= t2){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        ll t2 = 0;
        int idx = 0;
        vector<process> temp;
        for(auto p: processes){
            if(p.priority < lo){
                break;
            }
            if(p.priority - lo + 1 <= p.load)
                temp.push_back({p.id, lo, p.load});
            t2 += min(p.load, p.priority - lo + 1);
        }
        sort(temp.begin(), temp.end(), cmp);
        ll ans = -1;
        for(int i = temp.size() - 1; 0 <= i; i--){
            if(t2 == t){
                ans = temp[i].id;
                break;
            }
            t2--;
        }        
        cout << ans << "\n";
    }
    return 0;
}     