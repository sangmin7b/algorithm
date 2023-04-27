#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;
using ll = long long;

ll ccw(pii a, pii b, pii c){
    pii A = {b.X - a.X, b.Y - a.Y};
    pii B = {c.X - b.X, c.Y - b.Y};
    return ((ll)A.X * B.Y - (ll)A.Y * B.X);
}

int main(int argc, char const *argv[]){
    vector<pii> points;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    sort(points.begin(), points.end(), 
        [](pii a, pii b) -> bool{
            if(a.Y == b.Y){
                return a.X < b.X;
            }else{
                return a.Y < b.Y;
            }
        }
    );

    pii start_point = points[0];
    sort((points.begin() + 1), points.end(), 
        [&start_point](pii a, pii b)-> bool{
            if(ccw(start_point, a, b) > 0){
                return true;
            }else if(ccw(start_point, a, b) == 0){
                if(a.Y == b.Y){
                return a.X < b.X;
                }else{
                    return a.Y < b.Y;
                }
            }else{
                return false;
            }
        }
    );
    auto it = (points.begin()+1);
    stack<pii> s;
    pii prev = start_point;
    
    pii now = *it;
    s.push(prev);
    s.push(now);
    it++;
    while(it != points.end()){

        pii next = *it;
        if(ccw(prev, now, next) > 0){
            s.push(next);
            prev = now;
            now = next;
            it++;
        }else if(ccw(prev, now, next) == 0){
            now = next;
            it++;
            s.pop();
            s.push(now);
        }else{
            s.pop();
            s.pop();
            now = prev;            
            prev = s.top();
            s.push(now);
        }
    }
    vector<pii> border;
    while(!s.empty()){
        border.push_back(s.top());
        s.pop();
    }
    double max_dist = 0;
    for(int i=0;i<border.size()-1;i++){
        for(int j=i+1;j<border.size();j++){
            pii a = border[i];
            pii b = border[j];
            double dist = sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
            max_dist = max(max_dist, dist);
        }
    }
    cout.precision(12);
    cout << max_dist;
    return 0;
}
