#include<bits/stdc++.h>
using namespace std;
using matrix = vector<vector<int>>;
using ll = long long;
const int m = 1000003;

matrix mmult(const matrix &A, const matrix &B){
    matrix C(A.size(), vector<int>(B[0].size(), 0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B[0].size();j++){
            for(int k=0;k<B.size();k++){
                C[i][j] += ((ll)A[i][k] * B[k][j] ) % m;
                C[i][j] %= m;
            }
        }
    }
    return C;
}

matrix madd(const matrix &A, const matrix &B){
    matrix C(A.size(), vector<int>(A[0].size(), 0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            C[i][j] = A[i][j] + B[i][j];
            C[i][j] %= m;
        }
    }
    return C;
}

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int n, s, e, t;
    cin >> n >> s >> e >> t;
    s--; e--; 
    vector<matrix> A(7, matrix(n,vector<int>(n,0)));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x; cin >> x;
            x -= '0';
            if(x)
                A[x][i][j] = 1;
        }
    }
    matrix I(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        I[i][i] = 1;
    }
    matrix O(n, vector<int>(n, 0));
    function<matrix(int)> init = [&](int x){
        if(x == 6){
            return I;
        }
        matrix result(n ,vector<int>(n,0));
        for(int i=1;i<=5;i++){
            if(i + x > 6)
                break;
            result = madd(result, mmult(A[i], init(x+i)));
        }
        return result;
    };
    A[6] = init(0);
    int max_l = 0;
    int t2 = t;
    while(t2){
        max_l++;
        t2 /= 2;
    }
    vector<matrix> pows(max_l+1);
    pows[0] = I;
    pows[1] = A[6];
    for(int i=2;i<max_l+1;i++){
        pows[i] = mmult(pows[i-1],pows[i-1]);
    }    
    function<matrix(int)> pow = [&](int x){
        matrix result = pows[0];
        int i = 1;
        while(x){
            if(x%2){
                result = mmult(result, pows[i]);
            }
            i++;
            x /= 2;
        }
        return result;
    };
    function<matrix(int)> solve = [&](int x){
        if(x == 0)
            return I;
        if(x % 6 == 0)
            return pow(x/6);
        matrix result = O;
        for(int i=1;i<=5;i++){
            if(x < i)
                break;
            result = madd(result, mmult(A[i], mmult(pow((x-i)/6), solve((x-i) % 6))));
        }
        return result;
    };
    matrix result = solve(t);
    int ans = result[s][e];
    cout << ans << endl;
    for(auto v: result){
        for(auto i: v){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}