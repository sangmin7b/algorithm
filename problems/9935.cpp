#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    string s, bomb;
    cin >> s >> bomb;
    stack<pair<char, int>> st;
    map<char, int> bomb_state;
    for(int i = 0; i < bomb.size(); i++){
        bomb_state[bomb[i]] = i;
    }
    vi valid(s.size(), 1);
    int state = 0;
    for(int i = 0; i < s.size(); i++){
        if(bomb_state.find(s[i]) == bomb_state.end() || 
            ((bomb_state[s[i]] != state) && bomb_state[s[i]] != 0)
        ){
            while(!st.empty()){
                st.pop();
            }
            state = 0;
            continue;
        }
        if(bomb_state[s[i]] == 0){
            st.push({s[i], i});
            state = 1;
        }else{
            st.push({s[i], i});
            state++;
        }
        if(state == bomb.size()){
            for(int j = 0; j < bomb.size(); j++){
                auto p = st.top(); st.pop();
                valid[p.second] = 0;
            }
            if(st.empty()){
                state = 0;                
            }else{
                state = bomb_state[st.top().first] + 1;
            }
        }
    }
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(valid[i]){
            ans += s[i];
        }
    }
    if(ans.size() == 0){
        cout << "FRULA";
    }else{
        cout << ans;
    }
    return 0;
}     