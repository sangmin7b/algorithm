#include<bits/stdc++.h>
using namespace std;

vector<int> to_base_d(int N, int d){
    vector<int> result;
    do{
        result.push_back(N % d);
        N /= d;
    }while(N > 0);
    return vector<int>(result.rbegin(), result.rend());
}

int to_base_10(const vector<int>& N, int d){
    int result = 0;
    for(int c: N){
        result *= d;
        result += c;
    }
    return result;
}


int main(int argc, const char** argv) {
    int N, d;
    cin >> N >> d;    
    
    vector<int> now; 
    now.push_back(1);
    now.push_back(0);
    for(int i=2;i<d;i++){
        now.push_back(i);
    }
    do{
        if(to_base_10(now, d) > N){
            break;
        }
    }while(next_permutation(now.begin(), now.end()));   
    if(to_base_10(now, d) > N){
        cout << to_base_10(now, d);
    }else{
        cout << -1;
    }

    return 0;
}