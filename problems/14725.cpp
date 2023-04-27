#include<bits/stdc++.h>
using namespace std;
class node{
    public: 
        string s;
        vector<node> children;
        node(){

        }
        node(string s){
            this->s = s;
        }
};

void insert(node& parent, vector<string> info){
    if(info.size() == 0){
        return;
    }
    string first = info[0];
    for(node& child: parent.children){
        if(child.s == first){
            insert(child, vector<string>(info.begin()+1, info.end()));
            return;
        }
    }
    node newchild = node(first);
    insert(newchild, vector<string>(info.begin()+1, info.end()));
    parent.children.push_back(newchild);
}

void print(node parent, int depth){
    string dash = "--";
    if(parent.s != ""){
        for(int i=0;i<depth-1;i++){
            cout << dash;
        }
        cout << parent.s << "\n";
    }
    sort(parent.children.begin(), parent.children.end(), [](node a, node b){return a.s < b.s;});
    for(node child: parent.children){
        print(child, depth+1);
    }
}

int main(int argc, const char** argv) {
    int N; 
    cin >> N;
    vector<vector<string>> info(N);
    for(int i=0;i<N;i++){
        int l; cin >> l;
        for(int j=0;j<l;j++){
            string s;
            cin >> s;
            info[i].push_back(s);
        }
    }

    node root("");
    for(vector<string> v : info){
        insert(root, v);
    }
    print(root,0);
    return 0;
}