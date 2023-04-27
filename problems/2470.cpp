#include<bits/stdc++.h>
using namespace std;
int INF = 2100000000;
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<int> s;
    for(int i=0;i<N;i++){
        int v;
        cin >> v;
        s.push_back(v);
    }
    sort(s.begin(),s.end());
    
    function<int(int)> find_closest = [=](int x){
        int l = 0;
        int h = N-1;
        while(l < h - 1){
            int mid = (l + h) / 2;
            if(s[mid] > x){
                h = mid;
            }else{
                l = mid;
            }
        }
       
        if( abs(s[l] - x) > abs(s[h] - x)){
            return s[h];
        }else{
            return s[l];
        }
        
    };

    int min_sum = INF;
    pair<int, int> min_pair;

    for(int x: s){
        int rev = find_closest(-x);
        if (rev == x) continue;
        int sum1 = rev + x;
        if(abs(sum1) < abs(min_sum)){
            min_sum = sum1;
            min_pair = {x, rev};
        }
    }
    if(min_pair.first > min_pair.second){
        int temp = min_pair.second;
        min_pair.second = min_pair.first;
        min_pair.first = temp;
    }
    cout << min_pair.first << " " << min_pair.second;
    return 0;
}