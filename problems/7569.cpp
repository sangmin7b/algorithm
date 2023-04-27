#include<bits/stdc++.h>
#include <complex>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

struct point{
    int x; int y; int z;
    point operator+(const point &p){
        return {x + p.x, y+p.y, z+p.z};
    }
};

int N, M, H;
vvvi box;

bool is_inside(point p){
    return 0 <= p.z && p.z < H && 0 <= p.x && p.x < N && 0 <=p.y && p.y < M;
}

bool check(){
    for(int h=0;h<H;h++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(box[h][i][j] == 0)
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> M >> N >> H;
    box = vvvi(H, vvi(N,vi(M,0)));
    queue<point> q;
    for(int h=0;h<H;h++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> box[h][i][j];
                if(box[h][i][j] == 1){
                    q.push({i,j, h});
                }
            }
        }
    }
    int round = 0;
    while(!q.empty()){
        int t = q.size();
        round++;
        while(t--){
            point now = q.front();
            q.pop();
            for(auto d: {(point){1,0,0}, {-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}}){
                point next = now + d;
                if(!is_inside(next) || (box[next.z][next.x][next.y] != 0))
                    continue;
                box[next.z][next.x][next.y] = 1;
                q.push(next);
            }
        }
    }
    int ans = -1;
    if(check())
        ans = round - 1;
    cout << ans;
    return 0;
}