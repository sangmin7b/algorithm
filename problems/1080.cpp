#include<bits/stdc++.h>

using namespace std;
int A[50][50];
int B[50][50];

void flip(int r, int c){
    for(int i=r-1;i<=r+1;i++){
        for(int j=c-1;j<=c+1;j++){
            A[i][j] = !A[i][j];
        }
    }
    return;
}

int ctoi(char c){
    return c - '0';
}


int main(int argc, const char** argv) {
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            A[i][j] = ctoi(s[j]);
        }
    }    
    
    function<void(void)> printA = [=](){
        cout << "\n-----A-----\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    };

    function<void(void)> printB = [=](){
        cout << "\n-----B-----\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout << B[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    };


    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++){
            B[i][j] = ctoi(s[j]);
        }
    }    
    int cnt = 0;


    for(int i=0;i<N-2;i++){
        for(int j=0;j<M-2;j++){
            if(A[i][j] != B[i][j]){
                flip(i+1, j+1);
                cnt++;
            }
        }
    }    

    bool is_possible = true;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j] != B[i][j]){
                is_possible = false;
                break;
            }
        }
    }    

    if(is_possible){
        cout << cnt;
    }else{
        cout << -1;
    }


    return 0;
}