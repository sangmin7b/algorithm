#include<bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

void solve(){
    string cmd;
    cin >> cmd;
    stack<char> left, right;
    for(char c: cmd){
        switch (c){
        case '<':
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
            break;
        case '>':
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
            break;
        case '-':
            if(!left.empty()){
                left.pop();
            }
            break;
        default:
            left.push(c);
            break;
        }
    }
    stringstream ss;
    stack<char> left_rev;
    while(!left.empty()){
        left_rev.push(left.top());
        left.pop();
    }
    while(!left_rev.empty()){
        ss << left_rev.top();
        left_rev.pop();
    }
    while(!right.empty()){
        ss << right.top();
        right.pop();
    }
    cout << ss.str() << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}