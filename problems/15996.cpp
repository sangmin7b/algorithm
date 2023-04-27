#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(int argc, const char** argv) {
    int N, A;
    cin >> N >> A;
    ll sum = 0;
    for(ll Ak=A;Ak<=N;Ak*=A){
        sum += N / Ak;
    }
    cout << sum;
    return 0;
}