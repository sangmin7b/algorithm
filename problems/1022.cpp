#include<bits/stdc++.h>
using namespace std;
int O = 5000;
int val(int r, int c){
    int d = max(abs(r), abs(c));
    int start_point = (2 * d + 1) * (2 * d + 1); // (d, d)
    if(c == d && r == d){
        return start_point;
    }
    if(c >= r){
        start_point -= 4 * d; // (-d, -d)
        return start_point - (c + d) -  (r + d);
    }else{
        return start_point - (d - c) - (d - r);
    }
}

int len(int x){
    int l = 0;
    while(x){
        x /= 10;
        l++;
    }
    return l;
}

void print(int x, int l){
    for(int i=0;i<l-len(x);i++){
        cout <<" ";
    }
    cout << x << " ";
}

int main(int argc, char const *argv[]){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int max_v = 0;
    vector<vector<int>> ans(r2-r1+1, vector<int>(c2-c1+1, 0));
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            ans[i-r1][j-c1]=val(i, j);
            max_v = max(max_v, ans[i-r1][j-c1]);
        }
    }

    int len_m = len(max_v);
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            print(ans[i-r1][j-c1], len_m);
        }
        cout << "\n";
    }

    return 0;
}
