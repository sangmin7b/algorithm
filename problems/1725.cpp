#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N; cin >> N;
    stack<pair<int, int>> st;
    int ans = 0;
    for(int i = 0; i <= N; i++){
        int h; 
        if(i < N){
            cin >> h;
        }else{
            h = 0;
        }
        int idx = i;
        int x;
        while(!st.empty() && st.top().first >= h){
            tie(x, idx) = st.top(); st.pop();
            if(x == h){
                ans = max(ans, x * (i - idx + 1));
            }else{
                ans = max(ans, x * (i - idx));
            }
        }
        st.push({h, idx});
    }
    cout << ans;
    return 0;
}