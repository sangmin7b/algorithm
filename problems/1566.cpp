#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vvi arr;
vi r_sign;
vi c_sign;
int N, M;

bool check(){
    for(int i=0;i<N;i++){
        int sum = 0;
        for(int j=0;j<M;j++){
            sum += r_sign[i] * c_sign[j] *  arr[i][j];
        }
        if(sum < 0){
            return false;
        }
    }
    for(int j=0;j<M;j++){
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += r_sign[i] * c_sign[j] *  arr[i][j];
        }
        if(sum < 0){
            return false;
        }
    }
    return true;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    arr = vvi(N, vi(M, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }

    return 0;
}     