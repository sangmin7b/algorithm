#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node* next;
    node* prev;
    char value;
    node(char v){
        this->value = v;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

node* make_list(string s){
    node* start = new node(0);
    node* now = start;
    for(char c: s){
        node* next = new node(c);
        next->prev = now;
        now->next = next;
        now = next;
    }
    return now;
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    node* cursor = make_list(s);
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        char command;
        cin >> command;
        switch (command){
        case 'L':
            if(cursor->prev){
                cursor = cursor->prev;
            }
            break;
        case 'D':
            if(cursor->next){
                cursor = cursor->next;
            }            
            break;
        case 'B':
            if(cursor->prev){
                node* tmp = cursor;
                if(cursor->next){
                    cursor->next->prev = cursor->prev;
                }
                cursor->prev->next = cursor->next;
                cursor = cursor->prev;
                delete tmp;
            }
            break;
        case 'P':
            char c;
            cin >> c;
            node* p = new node(c);
            p->next = cursor->next;
            p->prev = cursor;
            if(cursor->next)
                cursor->next->prev = p;
            cursor->next = p;
            cursor = p;
            break;
        }
    }
    while(cursor->prev){
        cursor = cursor->prev;
    }
    int cnt = 0;
    while(cursor){
        if(cursor->value)
            cout << cursor->value;
        cursor = cursor->next;
    }
    cout << "\n";
    return 0;
}