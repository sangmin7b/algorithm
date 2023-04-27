#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* const argv[]){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr;
    vector<int> sorted;
    vector<int> R_position(1000001, 0);
    // vector<int> L_position(1000001, 0);
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sorted = arr;
    sort(sorted.begin(), sorted.end());
    for(int i=0;i<sorted.size();i++){
        R_position[sorted[i]] = max(R_position[sorted[i]], i);
    }
    int sum = 0;
    for(int i=0;i<N;i++){
        sum = max(sum,  i - R_position[arr[i]]);
    }
    cout << sum + 1 << "\n";
    return 0;
}