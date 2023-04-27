#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    string str;
    cin >> str;
    stack<char> s;
    stringstream ans;
    map<char, int> precedence;
    precedence.insert({'(', 0});
    precedence.insert({'+', 1});
    precedence.insert({'-', 1});
    precedence.insert({'*', 2});
    precedence.insert({'/', 2});

    int idx = 0;
    while(idx < str.length()){
        char token = str[idx];
        switch (token){
        case '(':
            s.push(token);
            break;
        case ')':
            while(s.top() != '('){
                ans << s.top();
                s.pop();
            }
            s.pop();
            break;
        case '*':
        case '/':
        case '+':
        case '-':
            while(!s.empty() && precedence[s.top()] >= precedence[token]){
                ans << s.top();
                s.pop();
            }
            s.push(token);
            break;
        default:
            ans << token;
            break;
        }
        idx++;
    }
    while(!s.empty()){
        ans << s.top();
        s.pop();
    }
    cout << ans.str();

    return 0;
}
