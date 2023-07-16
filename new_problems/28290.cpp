#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    map<string, string> m = {
        {"fdsajkl;", "in-out"},
        {"jkl;fdsa", "in-out"},
        {"asdf;lkj", "out-in"},
        {";lkjasdf", "out-in"},
        {"asdfjkl;", "stairs"},
        {";lkjfdsa", "reverse"}
    };
    string s; cin >> s;
    if(m.count(s)){
        cout << m[s];
    }else{
        cout << "molu";
    }
    return 0;
}     