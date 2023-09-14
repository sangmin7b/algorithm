#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

double rad(double x){
    double PI = 2 * acos(0);
    return x / 180 * PI;
}

double sqr(double x){
    return x * x;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    double D, H; cin >> D >> H;
    while(1){
        double a, b, c; cin >> a >> b >> c;
        if(a == 0) break;
        cout << round(H + D * sqrt(2 * 1 / (1 / sqr(tan(rad(a))) - 2 / sqr(tan(rad(b))) + 1 / sqr(tan(rad(c)))))) << "\n";
    }
    return 0;
}