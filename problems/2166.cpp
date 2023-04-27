//11785
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct point{
    ll x;
    ll y;
    point(){
        x = 0; y = 0;
    }
    point(int _x, int _y): x(_x), y(_y){};
};

ll ccw(point A, point B, point C){
    point v1(B.x - A.x, B.y - A.y);
    point v2(C.x - B.x, C.y - B.y);
    ll c = v1.x * v2.y - v1.y * v2.x; 
    return c;
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<point> p;
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        p.push_back(point(x, y));
    }
    ll area = 0;
    for(int i=1;i<N-1;i++){
        area += ccw(p[0], p[i], p[i+1]);
    }
    area *= 10;
    area /= 2;
    cout << abs(area) / 10 << "." << abs(area) % 10;
    return 0;
}