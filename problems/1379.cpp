#include<bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int,int>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> ans(N,0);
    priority_queue<pii, vector<pii>, greater<pii>> rooms;
    rooms.push({0,0});
    vector<pair<pii,int>> lectures(N);
    for(int i=0;i<N;i++){
        int idx, start, end;
        cin >> idx >> start >> end;
        idx--;
        lectures[i] = {{start,end},idx};
    }
    sort(lectures.begin(), lectures.end());
    for(pair<pii,int> lecture: lectures){
        if(rooms.top().first > lecture.first.first){
            rooms.push({lecture.first.second, rooms.size()});
            ans[lecture.second] = rooms.size()-1;
            continue;
        }
        pii top = rooms.top();
        rooms.pop();
        rooms.push({lecture.first.second,top.second});
        ans[lecture.second] = top.second;        
    }
    cout << rooms.size() << "\n";
    for(int x: ans){
        cout << x + 1 << "\n";
    }
    return 0;
}