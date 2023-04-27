#include<bits/stdc++.h>

using namespace std;
int S[200000];

int gcd(int a, int b){
    if(a < b){
        return gcd(b, a);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int gcd_range(int start, int end){
    int result = S[start];
    for(int i=start+1; i<=end; i++){
        result = gcd(result, S[i]);
    }
    return result;
}

int dfs(int start, int end){
    if(start == end){
        return S[start];
    }
    int mid = start + ((end - start + 1) / 2) - 1;
    int result1 = gcd_range(start, mid) + dfs(mid + 1, end);
    int result2 = gcd_range(mid+1, end) + dfs(start, mid);
    return max(result1, result2);
}

int main(int argc, char const *argv[]){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> S[i];
    }
    cout << dfs(0, N-1);


    return 0;
}
