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
    int N, M;
    cin >> N >> M;
    int package, single_string;
    cin >> package >> single_string;
    for(int i=1;i<M;i++){
        int a, b; cin >> a >> b;
        package = min(a, package);
        single_string = min(b, single_string);
    }
    int ans = min((N + 5) / 6 * package, N / 6 * package + N % 6 * single_string);
    ans = min(ans, N*single_string);
    cout << ans;
    return 0;
}     