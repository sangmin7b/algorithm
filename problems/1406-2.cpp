#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    vector<char> buffer(s.begin(), s.end());
    stack<char> rev_buffer;
    int M;
    cin >> M;
    while(M--){
        char cmd;
        cin >> cmd;
        switch (cmd){
        case 'L':
            if(!buffer.empty()){
                rev_buffer.push(buffer.back());
                buffer.pop_back();
            }
            break;
        case 'D':
            if(!rev_buffer.empty()){
                buffer.push_back(rev_buffer.top());
                rev_buffer.pop();
            }
            break;
        case 'B':
            if(!buffer.empty()){
                buffer.pop_back();
            }
            break;
        case 'P':
            char x; cin >> x;
            buffer.push_back(x);
            break;
        default:
            break;
        }
    }
    for(char c: buffer){
        cout << c;
    }
    while(!rev_buffer.empty()){
        cout << rev_buffer.top();
        rev_buffer.pop();
    }
    return 0;
}