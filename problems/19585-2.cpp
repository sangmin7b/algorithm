#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int p = 11111;
int P = 1000000007;
int next(int now, char x){
    return ((ll)now * p + x) % P;
}

int myhash(string s){
    int res = 0;
    for(char c: s){
        res = next(res, c-'a'+1);
    }
    return res;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int C,N;
    cin >> C >> N;
    unordered_multimap<int, string> c;
    unordered_multimap<int, string> n;
    c.reserve(2*C);
    n.reserve(2*N);
    for(int i=0;i<C;i++){
        string s;
        cin >> s;
        c.insert({myhash(s),s});        
    }
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        n.insert({myhash(string(s.rbegin(),s.rend())),s});
    }

    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        string s; 
        cin >> s;
        bool yes = 0;
        vector<int> hash;
        vector<int> rev_hash;
        int max_idx = min(1000, (int)s.size());
        int h1 = 0;
        for(int i=0;i<max_idx;i++){
            h1 = next(h1, s[i]-'a'+1);
            hash.push_back(h1);
        }
        int h2 = 0;
        for(int i=0;i<max_idx;i++){
            h2 = next(h2, s[s.size()-1-i]-'a'+1);
            rev_hash.push_back(h2);
        }
        for(int i=max((int)s.size()-max_idx-1,0);i<max_idx;i++){
            int h_i = hash[i];
            int rev_h_i = rev_hash[s.size()-2-i];
            if(c.find(h_i) != c.end() && n.find(rev_h_i) != n.end()){
                auto range = c.equal_range(h_i);
                string match1 = string(s.begin(), s.begin()+i+1);
                bool b1 = false;
                for(auto it = range.first; it != range.second; it++){
                    if((*it).second == match1){
                        b1 = true;
                    }
                }
                auto range2 = n.equal_range(rev_h_i);
                string match2 = string(s.begin()+i+1, s.end());
                bool b2 = false;
                for(auto it = range2.first; it != range2.second; it++){
                    if(it->second == match2){
                        b2 = true;
                    }
                }            
                if(b1 && b2){
                    yes = true;
                    break;
                }
            }

        }
        if(yes){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}