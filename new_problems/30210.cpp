#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

struct node{
    bool is_final;
    node *next_nodes[10];
    node(bool final){
        is_final = final;
        for(int i = 0; i < 10; i++){
            next_nodes[i] = nullptr;
        }
    }
};

void insert(node *root, string s){
    // cout << "insert : " << s << " \n"; 
    node *now = root;
    for(int i = 0; i < s.length() - 1; i++){
        char c = s[i];
        if(now->next_nodes[c - '0']){
            now = now->next_nodes[c - '0'];
        }else{
            now->next_nodes[c - '0'] = new node(false);
            now = now->next_nodes[c - '0']; 
        }
    }
    char c = s.back();
    if(now->next_nodes[c-'0']){
        now->next_nodes[c-'0']->is_final = true;
    }else{
        now->next_nodes[c-'0'] = new node(true);
    }
}

string find(node *root, string s){
    // cout << "find: " << s << " \n";
    if(s.length() == 0) return "";
    node *now = root;
    string res = "";
    for(char c: s){
        // cout << "c: " << c << " | final: " << now->is_final << "\n";
        node *next_node = NULL;
        int next_idx = -1;
        int max_r = 0;
        for(int i = 0; i < 10; i++){
            if(max_r <= (c-'0' + i) % 10 && now->next_nodes[i]){
                max_r = (c - '0' + i) % 10;
                if(now->next_nodes[i]){
                    next_node = now->next_nodes[i];
                }
                next_idx = i;
            }
        }
        // cout << " maxr : " << max_r << "\n";
        if(next_node){
            res += '0' + (c - '0' + next_idx) % 10;
            now = next_node;  
        }else if(now->is_final){
            res += '0' + (c - '0' + next_idx) % 10;
            res += s.substr(res.length(), s.length() - res.length());
            break;
            return res;
        }else{
            assert(0);
        }
    }
    // cout << "res: " << res << "\n";
    return res; 
}


int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<string> A, B;
    for(int i = 0; i < M; i++){
        string s; cin >> s;
        while(s.length()< N){
            s = "0" + s;
        }
        A.push_back(s);
    }
    for(int i = 0; i < M; i++){
        string s; cin >> s;
        while(s.length() < N){
            s = "0" + s;
        }
        B.push_back(s);
    }
    node root(false);
    insert(&root, A[0]);
    string B_res = "";
    for(int i = 1; i < M; i++){
        insert(&root, A[i]);
        B_res = max(B_res, find(&root, B[i]));
    }

    node root2(false);
    string A_res = "";
    for(int i = 1; i < M; i++){
        insert(&root2, B[i-1]);
        A_res = max(A_res, find(&root2, A[i]));
    }

    if(A_res < B_res){
        cout << "S";
    }else if(B_res < A_res){
        cout << "J";
    }else{
        cout << "D";
    }    
    return 0;
}     