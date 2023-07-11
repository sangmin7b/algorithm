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

vector<process> processes;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> Q >> N;
    for(int i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        processes.push_back({a, c, b});
    }
    sort(processes.begin(), processes.end(), cmp);    
    while(Q--){
        ll t; cin >> t;
        ll lo = -1e12, hi = 1e12;
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
        for(int i = 0; i < N; i++){
            auto p = processes[i];
            if(p.priority < lo){
                break;
            }
            t2 += min(p.load, p.priority - lo + 1);
            idx = i;
        }
        ll ans = -1;
        for(int i = idx; 0 <= i; i--){
            if(processes[i].load < processes[i].priority - lo + 1){
                continue;
            }
            if(t2 == t){
                ans = processes[i].id;
                break;
            }
            t2--;
        }        
        assert(0 < ans);
        cout << ans << "\n";
    }
    return 0;
}     