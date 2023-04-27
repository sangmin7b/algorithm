#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void solve(){
    int N, M;
    cin >> N >> M;
    vector<pair<bitset<100>, int>> nums_result;
    vi used(N, 0);
    for(int i=0;i<M;i++){
        string s; 
        int x;
        cin >> s >> x;
        nums_result.push_back({bitset<100>(s), x});
    }
    while(!nums_result.empty()){
        bool erased = false;
        for(int i=0;i<N;i++){
            if(used[i]){
                continue;
            }
            bool ok[2] = {true, true};
            int flag[2] = {-1, -1};
            for(int j=0;j<nums_result.size();j++){
                int b = nums_result[j].first[i];
                if(flag[b] == -1){
                    flag[b] = nums_result[j].second;
                    continue;
                }
                if(flag[b] != nums_result[j].second){
                    ok[b] = false;
                }
            }
            
            for(int b=0;b<2;b++){
                if(!ok[b]){
                    continue;
                }
                int j = 0;
                while(j < nums_result.size()){
                    if(b == nums_result[j].first[i]){
                        nums_result.erase(nums_result.begin()+j);
                        continue;
                    }
                    j++;
                }
                erased = true;
                used[i] = 1;                
                break;
            }            
        }
        if(!erased){
            int res = nums_result[0].second;
            for(auto p: nums_result){
                if(p.second != res){
                    cout << "LIE\n";
                    return;
                }
            }
            cout << "OK\n";
            return;
        }
    }
    cout << "OK\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}