#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi sum;
int get_sum(int x, int y){
    if(x < 0 || y < 0)
        return 0;
    return sum[x][y];
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int N, M;
    cin >> N >> M;
    vvi nums(N,vi(N, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> nums[i][j];
        }
    }
    sum = vvi(N,vi(N,0));
    sum[0][0] = nums[0][0];
    for(int j=1;j<N;j++){
        sum[0][j] = sum[0][j-1] + nums[0][j];
    }
    for(int i=1;i<N;i++){
        sum[i][0] = sum[i-1][0] + nums[i][0];    
        for(int j=1;j<N;j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + nums[i][j]; 
        }
    }
    for(int i=0;i<M;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 2; y1 -= 2; x2--; y2--;
        cout << get_sum(x2, y2) - get_sum(x2, y1) - get_sum(x1, y2) + get_sum(x1, y1) << "\n";
    }
    return 0;
}