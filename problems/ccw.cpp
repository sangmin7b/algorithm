//11785
#include<bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    point(){
        x = 0; y = 0;
    }
    point(int _x, int _y): x(_x), y(_y){};
};

int ccw(point A, point B, point C){
    point v1(B.x - A.x, B.y - A.y);
    point v2(C.x - B.x, C.y - B.y);
    int c = v1.x * v2.y - v1.y * v2.x; 
    if(c > 0){
        return 1;
    }else if(c<0){
        return -1;
    }else{
        return 0;
    }
}

int main(int argc, const char** argv) {
    point p[3];
    for(int i=0;i<3;i++){
        int x,y;
        cin >> x >> y;
        p[i] = point(x, y);
    }
    cout << ccw(p[0], p[1], p[2]);
    return 0;
}