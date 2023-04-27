#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using ll = long long;

class dsu{
    vector<int> parent;
    vector<int> size;
    public:
        int find(int a){
            if(parent[a] != a){
                parent[a] = find(parent[a]);
            }
            return parent[a];
        }

        void union_set(int a, int b){
            int p1 = find(a);
            int p2 = find(b);
            if(p1 != p2){
                if(size[p1] < size[p2]){
                    swap(p1, p2);
                }
                parent[p2] = p1;
                size[p1] += size[p2];
            }
        }

        dsu(int N){
            parent = vector<int>(N,0);
            size = vector<int>(N, 1);
            for(int i=0;i<N;i++){
                parent[i] = i;
            }
        }
};

int main(int argc, const char** argv) {
    return 0;
}