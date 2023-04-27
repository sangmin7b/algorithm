#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<string> words(N);
    for(int i=0;i<N;i++){
        cin >> words[i];
    }
    vector<int> count(26, 0);
    for(string word: words){
        int m = 1;
        for(auto it = word.rbegin();it!=word.rend();it++){
            count[*it - 'A'] += m;
            m *= 10;
        }
    }
    sort(count.begin(), count.end(), greater<int>());
    int ans = accumulate(count.begin(), count.end(), 0, [=](int result, int x){
        static int val = 9;
        return result + x * val--;
    });
    cout << ans;
    return 0;
}