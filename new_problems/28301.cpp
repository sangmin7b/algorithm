#include<bits/stdc++.h>

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
    int N, M, C;
    cin >> N >> M >> C;
    // min1, min2, max
    // min1 + C > min2 이면 
    // min1 + x <= max 일 때까지는 x가 클수록 이득
    // (diff: max - min2, val : min1 + x + min2 + ... + max)
    // (diff start: max - min2, diff end: min1 + C - min2, val : min1 + x + min2 + ... + max )
    // 그 이후로는 합은 x가 커질수록 증가, 차이는 min1 + x - min2
    // min1 + C < min2 이면 min1 + C를 하는게 이득, 차이는 max - min1 - C
    //              -----------------
    //             /
    //            / 
    //           /
    //      ----/
    //      |
    //  -----
    // 함수 f만 구현하면 됨 
    // 연속 구간인지 아닌지 판별 - 
    // sorted array,  range (int start, int end, int start value, bool continuous)
    // start가 x이하이면서 가장 큰 element를 찾은 뒤 f(x) 계산
    
    return 0;
}     