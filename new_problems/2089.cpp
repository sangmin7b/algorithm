#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    if(N == 0){
        cout << 0;
        return 0;
    }
    vector<int> ans;
    while(N){
        if(N % 2){
            if(N < 0){
                N--;
            }       
            ans.push_back(1);     
        }else{
            ans.push_back(0);
        }
        N /= 2;
        N = -N;
    }
    for(auto it=ans.rbegin();it!=ans.rend();it++){
        cout << *it;
    }
    return 0;
}