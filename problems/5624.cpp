#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]){
    int N;
    const int offset = 100000;
    cin >> N;
    vector<int> arr(N,0);
    vector<bool> sum_two(2 * offset + 1, 0);
    vector<bool> possible(N, 0);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[i] - arr[j] < -offset || arr[i] - arr[j] > offset){
                continue;
            }
            if(sum_two[arr[i] - arr[j] + offset]){
                possible[i] = 1;
                break;
            }
        }
        for(int j=0;j<=i;j++){
            if(arr[i] + arr[j] < -offset || arr[i] + arr[j] > offset){
                continue;
            }
            sum_two[arr[i] + arr[j] + offset] = 1;
        }
    }
    int ans = 0 ;
    for(bool b: possible){
        if(b){
            ans++;
        }
    }
    cout << ans;

    return 0;
}