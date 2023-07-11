#include<bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vi name(N * N + 1, 0);
    iota(name.begin(), name.end(), 0);    
    // 1, 2
    // 3, 4
    //   1, 2, N + 1, N + 2의 좌표만 추적 
    //   (r, c)위치의 숫자 -> 
    //              1, 2, N+1, N +2 와 홀짝성이 같은 수 찾기
    //               그 숫자와의 거리 dr, dc,  x + (N * dr) % (N * N) + (dc + N)% N
    //              name에서 숫자 바꾸기 
    // 
    vi key_idx = {1, 2, N + 1, N + 2};
    vector<pi> key = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    for(int i = 0; i < Q; i++){
        string s; cin >> s;
        if(s == "RO"){
            for(auto &p: key){
                if(p.first % 2 == 1){
                    p.second++;
                    if(p.second == N + 1){
                        p.second = 1;
                    }
                }
            }
        }else if(s == "RE"){
            for(auto &p: key){
                if(p.first % 2 == 0){
                    p.second++;
                    if(p.second == N + 1){
                        p.second = 1;
                    }
                }
            }       
        }else if(s == "CO"){
            for(auto &p: key){
                if(p.second % 2 == 1){
                    p.first++;
                    if(p.first == N + 1){
                        p.first = 1;
                    }
                }
            }
        }else if(s == "CE"){
            for(auto &p: key){
                if(p.second % 2 == 0){
                    p.first++;
                    if(p.first == N + 1){
                        p.first = 1;
                    }
                }
            }            
        }else{
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;             
            int idx1 = 0, idx2 = 0;
            for(int i = 0; i < 4; i++){
                auto p = key[i];
                if((p.first % 2 == r1 % 2 )&& (p.second % 2 == c1 % 2)){
                    idx1 = key_idx[i] + (c1 - p.second + N) % N + ((r1 - p.first + N) % N) * N;
                }
            }
            for(int i = 0; i < 4; i++){
                auto p = key[i];
                if((p.first % 2 == r2 % 2) && (p.second % 2 == c2 % 2)){
                    idx2 = key_idx[i] + (c2 - p.second + N) % N + ((r2 - p.first + N) % N) * N;
                }
            }
            // cout << "idx: " << idx1 << " " << idx2 << "\n";
            // cout << "name: " << name[idx1] << " " << name[idx2] << "\n";
            swap(name[idx1], name[idx2]);            
        }
    }
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            int idx = 0;            
            for(int i = 0; i < 4; i++){
                auto p = key[i];
                if((p.first % 2 == r % 2)&& (p.second % 2 == c % 2)){
                    idx = key_idx[i] + (c - p.second + N) % N + ((r - p.first + N) % N) * N;
                    break;
                }
            }
            cout << name[idx] << " ";
        }
        cout << "\n";
    }
    return 0;
}     