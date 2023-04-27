#include<bits/stdc++.h>
using namespace std;

void solve(){
    multiset<int> count;
   priority_queue<int, vector<int>, greater<int>> min_q;
   priority_queue<int> max_q;
    int k; cin >> k;
    for(int i=0;i<k;i++){
        char c; int n;
        cin >> c >> n;
        if(c == 'I'){
            min_q.push(n);
            max_q.push(n);
            count.insert(n);
        }else{
            if(n > 0){
                while(!max_q.empty() && count.find(max_q.top()) == count.end()){
                    max_q.pop();
                }
                if(max_q.size() == 0){
                    continue;
                }
                int max_n = max_q.top();
                count.erase(count.find(max_n));
                max_q.pop();
            }else{
                while(!min_q.empty() && count.find(min_q.top()) == count.end()){
                    min_q.pop();
                }
                if(min_q.size() == 0){
                    continue;
                }
                int min_n = min_q.top();
                count.erase(count.find(min_n));
                min_q.pop();
            }
        }
    }
    while(!max_q.empty() && count.find(max_q.top()) == count.end()){
        max_q.pop();
    }
    
    while(!min_q.empty() && count.find(min_q.top()) == count.end()){
        min_q.pop();
    }
    if(max_q.empty()){
        cout << "EMPTY ";
    }else{
        cout << max_q.top() << " " << min_q.top() <<"\n";
    }

}


int main(int argc, char const *argv[]){
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
