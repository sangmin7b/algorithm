#include<bits/stdc++.h>

using namespace std;
double INF = 1234e12;
int main(int argc, char const *argv[]){
    int N;
    cin >> N;
    vector<int> buildings;
    for(int i=0;i<N;i++){
        int h;
        cin >> h;
        buildings.push_back(h);
    }    
    vector<int> count(N,0);
    for(int i=0;i<N-1;i++){
        double max_g = -INF;
        for(int j=i+1;j<N;j++){  
            int dist = j - i;
            int dh = buildings[j] - buildings[i];
            double grad = (double)dh / dist;
            if(grad > max_g){
                count[i]++;
                count[j]++;
                max_g = grad;
            }
        }
    }
    int ans = *max_element(count.begin(), count.end());
    cout << ans;
    return 0;
}
