#include<bits/stdc++.h>
using namespace std;

int N, K;

int main(int argc, char const *argv[]){
    cin >> N >> K;
    int L = (K + 1) / 2;
    vector<int> monsters;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        monsters.push_back(x);
    }
    set<int> s = set<int>();
    int score = 0;
    int idx = N - 1;
    for(int i=0;i<K;i++){
        if(monsters[idx] == 0){
            break;
        }
        int score1 = s.size();
        s.insert(monsters[idx]);
        int score2 = s.size();
        if(score1 < score2){
            idx--;
        }else{
            score = score2;
            break;
        }
    }
    s = set<int>();
    while(idx > K){
        
    }


    return 0;
}
