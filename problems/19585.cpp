#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    vector<TrieNode*> children;
    bool is_end;

    public: 
        TrieNode(){
            is_end = false;
            children = vector<TrieNode*>(26, NULL);
        }

        static void insert(TrieNode* root, string key){
            TrieNode* now = root;
            for(char c: key){
                int idx = c - 'a';
                if(now->children[idx] == NULL){
                    now->children[idx] = new TrieNode();
                }
                now = now->children[idx];
            }
            now->is_end = true;   
        }

        static bool search(TrieNode* root, string key){
            TrieNode* now = root;
            for(char c: key){
                int idx = c - 'a';
                if(!now->children[idx]){
                    return false;
                }
                now = now -> children[idx];
            }
            return now->is_end;
        }

        static int searchidx(TrieNode* root, string key){
            TrieNode* now = root;
            for(char c: key){
                int idx = c - 'a';
                if(!now->children[idx]){
                    return false;
                }
                now = now -> children[idx];
            }
            return now->is_end;
        }
};

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int C,N;
    cin >> C >> N;
    TrieNode root;
    vector<string>colors;
    vector<string>names;

    for(int i=0;i<C;i++){
        string s;
        cin >> s;
        colors.push_back(s);      
    }
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        names.push_back(s);        
    }

    for(string color: colors){
        for(string name: names){
            string s = color + name;
            root.insert(&root, s);
        }
    }

    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        string s; 
        cin >> s;
        if(root.search(&root, s)){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}