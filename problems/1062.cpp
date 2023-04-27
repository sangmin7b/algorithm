#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll wtol(string word){
    ll res = 0;
    for(char c: word){
        int offset = c - 'a';
        res |= (1LL << offset);
    }
    return res;
}
ll vtol(vector<int>& lv, vector<int>& offsets){
    ll res = 0;
    for(int i=0;i<21;i++){
        if(lv[i]){
            res |= (1LL << (offsets[i]));
        }
    }
    return res;
}

int main(int argc, const char** argv) {
    int N, K;
    cin >> N >> K;
    vector<string> words(N);
    vector<ll> encoded_words(N);

    for(int i=0;i<N;i++){
        cin >> words[i];
        encoded_words[i] = wtol(words[i]);
    }

    // 'a', 'c', 'i', 'n', 't'
    set<int> essentials = {'a' - 'a', 'c' - 'a', 'i' - 'a', 'n' - 'a', 't' - 'a'};
    if(K < essentials.size()){
        cout << 0;
        return 0;
    }

    vector<int> offsets;
    for(int i=0;i<26;i++){
        if(essentials.find(i) == essentials.end()){
            offsets.push_back(i);
        }
    }

    ll est = 0;
    for(int i:essentials){
        est |= (1LL << i);
    }
    vector<int> letters;
    for(int i=0;i<21;i++){
        if(i + K - 5 < 21){
            letters.push_back(0);
        }else{
            letters.push_back(1);
        }
    }
    int mcnt = 0;
    do{
        int cnt = 0;
        for(ll word: encoded_words){
            ll v = vtol(letters, offsets);
            if((word & (est | vtol(letters, offsets)))== word){
                cnt++;
            }
        }        
        mcnt = max(mcnt, cnt);
    } while (next_permutation(letters.begin(), letters.end()));

    cout << mcnt;
    return 0;
}