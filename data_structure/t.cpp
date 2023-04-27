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

    int N = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        cout << i % 10;
    }
    cout << "\n";
    for(int i=0;i<N;i++){
        cout << (i + 3) % 10;
    }
    return 0;
}     