#include<bits/stdc++.h>
//naive solution
using namespace std;
using ll = long long;

inline int mult(int a, int b, int N){
    ll c = (ll) a * b;
    if (c > N){
        c %= N;
    }
    return c;
}
inline int add(int a, int b, int N){
    ll c = (ll) a + b;
    if (c > N){
        c %= N;
    }
    return c;
}

void solve(int N, int a, int b){
    int remains = N;
    int now = 0;
    set<int> s;
    unordered_map<int, int> ord;
    s.insert(now);
    ord.insert({now, 0});
    while(1){
        int next = add (mult (mult(a, now, N), now, N), b, N);
        now = next;
        if(s.find(now) != s.end()){
            break;
        }
        ord.insert({now, s.size()});
        s.insert(now);
    }
    
    remains = N - s.size() + ord.at(now);
    cout << remains << "\n";

}

int main(int argc, char const *argv[]){
    int N, a, b;
    while(1){
        cin >> N;
        if(N == 0) break;
        cin >> a >> b;
        solve(N, a, b);
    }

    return 0;
}
