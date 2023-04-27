#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    const int MAX = 1000001;
    vector<int> memo(1000001, MAX);
    vector<function<int(int)>> funs = {[&](int x){
        return (x%2 == 0) ? memo[x/2] + 1: MAX;
        },
        [&](int x){
        return (x%3 == 0) ? memo[x/3] + 1 : MAX;
        },
        [&](int x){
        return memo[x-1] + 1;
        }
    };
    memo[1] = 0;
    for(int i=2;i<=N;i++){
        int m = MAX;
        for(auto f: funs){
            m = min(m, f(i));
        }
        memo[i] = m;
    }
    int ans = memo[N];
    cout << ans;
    return 0;
}