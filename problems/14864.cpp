#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int FWTree[100001];
int N, M;

int LSB(int x){
    return x & (-x);
}

int FW_get(int idx){
    int sum = 0;
    while(idx > 0){
        sum += FWTree[idx];
        idx -= LSB(idx);
    }
    return sum;
}

void FW_add(int idx, int x){
    while(idx <= N){
        FWTree[idx] += x;
        idx += LSB(idx);
    }
}

bool check(vector<pii>& pairs, vector<int>& rank){
    for(pii p: pairs){
        if(rank[p.first] < rank[p.second]){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]){
    cin >> N >> M;
    vector<int> rank(N,1);
    vector<pii> pairs;
    for(int i=0;i<M;i++){
        int x, y; 
        cin >> x >> y;
        x--; y--;
        rank[x]++;
        pairs.push_back({x,y});
    }
    for(int i=0;i<N;i++){
        int target = rank[i];
        int l = 0, r = N;
        while(l < r){
            int mid = (l + r) / 2;
            if(mid - FW_get(mid) >= target ){
                r = mid;
            }else{
                l = mid + 1;
            }        
        }
        rank[i] = l;
        FW_add(rank[i], 1);
    }    

    if(check(pairs, rank)){
        for(int i=0;i<N;i++){
            cout << rank[i] << " ";
        }
    }else{
        cout << "-1";
    }
    return 0;
}
