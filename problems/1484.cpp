#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int G;
    cin >> G;
    int cnt = 0;
    int l = 1, r = 2;
    while(2 * l < G){
        while(r * r - l * l < G){
            r++;
        }
        while(G < r * r - l * l){
            l++;
        }
        if(r * r - l * l == G){
            cout << r << "\n";
            cnt++;
        }
        r++;
    }
    if(cnt == 0){
        cout << -1;
    }
    return 0;
}     