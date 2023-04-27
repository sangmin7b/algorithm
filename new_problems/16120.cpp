#include<bits/stdc++.h>
#include <deque>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

/*
    X -> P
        | XXAX
    P
    PPAP
    PPAP PAP
    PPAP PPAP AP
    PPPAPAPPPAPAPPAP               
*/
string s; 
bool solve(int start, int end){
    if(start == end){
        return s[start] == 'P';
    }
    if(start + 3 == end){
        return s.substr(start, 4) == "PPAP";
    }
    int idx = end;
    while(start <= idx && s[idx] != 'A'){
        idx--;
    }
    if(idx == end || idx < start + 2){
        return false;
    }
    if(!solve(idx+1, end)){
        return false;
    }
    for(int i=start;i<idx;i++){
        if(solve(start, i) && solve(i+1, idx-1)){
            return true;
        }
    }
    return false;
}

int main(int argc, const char** argv) {
    cin >> s;
    string ppap = "PPAP";
    stack<char> sc;
    deque<char> window;
    for(char c: s){
        sc.push(c);
        if(c == 'P' && 4 <= sc.size()){
            bool matched = true;
            vector<char> t(4);
            for(int i=3;0<=i;i--){
                t[i] = sc.top();
                sc.pop();
            }
            for(int i=0;i<4;i++){
                if(t[i] != ppap[i]){
                    matched = false;
                }
            }
            if(matched){
                sc.push('P');
            }else{
                for(int i=0;i<4;i++){
                    sc.push(t[i]);
                }
            }
        }
    }
    if(sc.size() == 1 && sc.top() == 'P'){
        cout << "PPAP";
    }else{
        cout << "NP";
    }
    return 0;
}     