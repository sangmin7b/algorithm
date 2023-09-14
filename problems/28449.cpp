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
    int N, M; cin >> N >> M;
    vi A(1e5, 0);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        A[x]++;
    }
    for(int i = 0; i < 1e5; i++){
        A[i+1] += A[i];
    }
    ll hi = 0, arc = 0, draw = 0;
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        arc += A[x-1];
        draw += A[x] - A[x-1];
        hi += N - A[x];
    }
    cout << hi << " " << arc << " " << draw;
    return 0;
}     