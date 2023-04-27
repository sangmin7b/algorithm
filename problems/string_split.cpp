#include<bits/stdc++.h>
using namespace std;
vector<string> split(string s, char delim){
    vector<string> result;
    stringstream ss(s);
    string t;
    while(getline(ss, t, delim)){
        result.push_back(t);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    
    transform(splited.begin(), splited.end(), back_inserter(singers), [](string snum){return stoi(snum);});
    return 0;
}
