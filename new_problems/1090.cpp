#include<bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N;
vector<pi> points;

int dist(pi &a, pi &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool test_one(pi p, int d, int k){
    int x = p.first, y = p.second;
    for(int dx=0;dx<=d;dx++){
        int dy = d - dx;
        pi next[4] = {{x+dx, y+dy}, {x+dx, y-dy}, {x-dx,y+dy}, {x-dx,y-dy}};
        for(pi n: next){
            if(n.first < 1 || 1e6 < n.first || n.second < 1 || 1e6 < n.second){
                continue;
            }
            int cnt = 0;
            for(pi p2: points){
                if(dist(n, p2) <= d){
                    cnt++;
                }
            }
            if(k <= cnt){
                return true;
            }
        }
    }
    return false;
}

bool test_all(int d, int k){
    for(pi p: points){
        if(test_one(p, d, k)){
            return true;
        }
    }
    return false;
}

int find_min(int k){
    int lo = 0, hi = 2e6;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(test_all(mid, k)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    return lo;    
}

int main(int argc, const char** argv) {
    cin >> N;
    points = vector<pi>(N);
    for(auto &p: points){
        cin >> p.first >> p.second;
    }    
    for(int i=1;i<=N;i++){
        cout << find_min(i) << " ";
    }
    return 0;
}     