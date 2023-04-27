#include<bits/stdc++.h>
using namespace std;

vector<string> tokenizer(string str, char del){
    vector<string> tokens;
    stringstream ss(str);
    string tmp;
    while(getline(ss, tmp, del)){
        tokens.push_back(tmp);
    }
    return tokens;
}
void solve(){
    string p; cin >> p;
    int n;  cin >> n;
    string s; cin >> s;
    string s2(s.begin()+1, s.end()-1);
    vector<string> tokenized = tokenizer(s2, ',');
    vector<int> arr;
    stringstream ss;

    for(string t: tokenized){
        arr.push_back(stoi(t));
    }

    bool reversed = 0;
    int left = 0;
    int right = arr.size();
    for(char c: p){
        if(c == 'R'){
            reversed = !reversed;
        }else{
            if(reversed){
                right--;
            }else{
                left++;
            }
        }
    }
    if(left > right){
        cout << "error\n";
    }else{
        cout << "[";
        if(reversed){
            for(int i=right-1;i>=left;i--){
                cout << arr[i];
                if(i != left){
                    cout << ",";
                } 
            }
        }else{
            for(int i=left;i<=right-1;i++){
                cout << arr[i];
                if(i != right-1){
                    cout << ",";
                } 
            }
        }
        cout << "]";
        cout << "\n";
      
    }


}

int main(int argc, const char** argv) {
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}