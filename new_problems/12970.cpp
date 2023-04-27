#include<bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    if(N / 2 * ((N + 1) / 2) < K){
        cout << -1;
        return 0;
    }
    int D = K / (N / 2);
    int R = K % (N / 2);
    vector<char> ans;
    for(int i=0;i<N/2;i++){
        if(i == R && R != 0){
            ans.push_back('B');
        }
        ans.push_back('A');        
    }
    for(int i=0;i<D;i++){
        ans.push_back('B');
    }
    while(ans.size() < N){
        ans.push_back('A');
    }
    for(char c: ans){
        cout << c;
    }
    // 5 8
    // 최대 n/2 * (n+1)/2 
    // aabbb
    // 5 4
    // aaaab
    // 5 3
    // baaab
    // 6 8
    // aababb
    // 3 3 + 2

    // AABB
    //

    return 0;
}     