#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    int N;
    cin >> N;
    vector<string> titles(N);
    vector<string> diffs(N);
    for(int i=0;i<N;i++){
        cin >> titles[i];
        cin >> diffs[i];
    }
    vector<string> ans(N,"");
    for(int i=0;i<N;i++){
        if(diffs[i] == "SAME"){
            ans[i] = titles[i];
        }
    }
    for(int i=0;i<N;i++){
        if(diffs[i] == "DOWN"){
            for(int j=0;j<i;j++){
                if(ans[j] == ""){
                    ans[j] = titles[i];
                    break;
                }
            }
        }
    }
    for(int i=N-1;i>=0;i--){
        if(diffs[i] == "UP"){
            for(int j=N-1;j>i;j--){
                if(ans[j] == ""){
                    ans[j] = titles[i];
                    break;
                }
            }
        }
    }
    for(string s: ans){
        cout << s << "\n";
    }
    return 0;
}
