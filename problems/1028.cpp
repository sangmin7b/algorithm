#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
bool m_data[750][750];
int upper[750][750];
int lower[750][750];

int main(int argc, const char** argv) {
    int R, C;
    cin >> R >> C;

    for(int i=0;i<R;i++){
        string s;
        cin >> s;
        for(int j=0;j<C;j++){
            m_data[i][j] = s[j] == '1';
        }
    }
    for(int S=0;S<R+C-1;S++){
        int count = 0;
        for(int i=0;i<R;i++){
            int j = S - i;
            if(i >= R || i < 0 || j >= C || j < 0 ) continue;
            if(m_data[i][j]){
                count++;
            }else{
                count = 0;
            }
            lower[i][j] = count;
        }
    }
    for(int S=1-C;S<R;S++){
        int count = 0;
        for(int i=0;i<R;i++){
            int j = i - S;
            if(i >= R || i < 0 || j >= C || j < 0 ) continue;
            if(m_data[i][j]){
                count++;
            }else{
                count = 0;
            }
            lower[i][j] = min(lower[i][j], count);
        }
    }
    for(int S=0;S<R+C-1;S++){
        int count = 0;
        for(int i=R-1;i>=0;i--){
            int j = S - i;
            if(i >= R || i < 0 || j >= C || j < 0 ) continue;
            if(m_data[i][j]){
                count++;
            }else{
                count = 0;
            }
            upper[i][j] = count;
        }
    }
    for(int S=1-C;S<R;S++){
        int count = 0;
        for(int i=R-1;i>=0;i--){
            int j = i - S;
            if(i >= R || i < 0 || j >= C || j < 0 ) continue;
            if(m_data[i][j]){
                count++;
            }else{
                count = 0;
            }
            upper[i][j] = min(upper[i][j], count);
        }
    }   
    int max_size = 0;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(upper[i][j]){
                int size = upper[i][j];
                while(size > max_size){
                    int dist = (size - 1) * 2;
                    if(i+dist < R && lower[i+dist][j] >= size){
                        max_size = max(max_size, size);
                        break;
                    }
                    size--;
                }
            }
            
        }
    }
    cout << max_size;
    

    return 0;
}