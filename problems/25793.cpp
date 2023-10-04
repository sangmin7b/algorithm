#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        ll R, C; cin >> R >> C;
        ll x = min(R, C);
        ll d = max(R, C) - x;
        ll w = x * (x - 1) * (2 * x - 1) / 3 + d * x * (x - 1) + x * (x + d);
        ll b = x * (x + 1) * (2 * x + 1) / 3 + (d - 1) * x * (x + 1) - d * x;
        cout << w << " " << b << "\n";
    }
    return 0;
}     