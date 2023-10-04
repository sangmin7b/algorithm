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
    int x, b;   cin >> x >> b;
    vi ans;
    if(b < 0){
        do{
            int r = x % abs(b);
            if(r < 0){
                r += abs(b);
                x -= r;
            }
            ans.push_back(r);
            x /= b;
        }while(x);
    }else{
        int n = abs(x);
        if(x < 0){
            cout << '-';
        }
        do{
            ans.push_back(n % b);
            n /= b;
        }while(n);
    }
    for(auto it=ans.rbegin();it != ans.rend(); it++){
        cout << *it;
    }
    return 0;
}     