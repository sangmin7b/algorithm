#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using point = complex<double>;
const double PI = 2 * acos(0);
const doubl

eps = 1e-6;

vector<point> points;
ll N;

double arg2(int i){
    if(N <= i){
        return arg(points[i % N]) + 2 * PI;        
    }else{
        return arg(points[i]);
    }
}

int main(int argc, const char** argv) {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    double x, y; cin >> x >> y;
    point P = {x, y};
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        points.push_back((point){x, y} - P);
    }
    auto cmp = [](point &a, point &b){
        return arg(a) < arg(b);
    };
    sort(points.begin(), points.end(), cmp);
    cout << "\n";
    for(auto p: points){
        cout << p.real() << " " << p.imag() <<" \n";
    }
    cout << "\n";
    ll ans = 0;
    int idx = 0;
    for(int i = 0; i < N; i++){
        while(arg2(idx) - arg2(i) < PI){
            idx++;
            if(idx % N == i){
                break;
            }
        }
        cout << "i: " << i << " idx : " << idx << "\n";
        ll cnt = idx - i - 1;
        if(abs(arg2(idx) - arg2(i) - PI) < eps){
            ans += (N - 2 - cnt) * cnt;
        }else if(idx % N == i){
            ans += cnt;
        }else{
            ans += (N - 1 - cnt) * cnt;
        }
        cout << i << " " << idx << " " << "ans : " << ans << " \n";
    }
    cout << ans;
    return 0;
}     