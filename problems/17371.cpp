#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using point = pair<int,int>;
using pp = pair<point, point>;

int square(int x){
    return x * x;
}

int dist(point p1, point p2){
    return (square(p1.first - p2.first) + square(p1.second - p2.second));
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<point> points;
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    point ans;
    int ans_dist = INT32_MAX;
    for(int i=0;i<N;i++){
        int max_dist = 0;
        point max_p = points[i];
        for(int j=0;j<N;j++){
            if(dist(points[i], points[j]) > max_dist){
                max_dist = dist(points[i], points[j]);
                max_p = points[j];
            }    
        }
        if(max_dist < ans_dist){
            ans_dist = min(ans_dist, max_dist);
            ans = points[i];
        }
    }
    cout << ans.first << " " << ans.second;
    return 0;
}