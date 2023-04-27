/*
    Kruskal algorithm
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
class uf{
    vector<int> parent;
    public:
        int _find(int a){
            if(parent[a] == a){
                return a;
            }
            parent[a] = _find(parent[a]);
            return parent[a];
        }

        void _union(int a, int b){
            int p1 = _find(a);
            int p2 = _find(b);
            if(p1 != p2){
                parent[p2] = p1;
            }
        }

        uf(int N){
            parent = vector<int>(N,0);
            for(int i=0;i<N;i++){
                parent[i] = i;
            }
        }
};


int main(int argc, const char** argv) {
    int V, E;
    cin >> V >> E;
    priority_queue<pair<int, pii>> pq;
    long long sum = 0;
    uf U(V);
    for(int i=0;i<E;i++){
        int from, to, w;
        cin >> from >> to >> w;
        from--; to--;
        pq.push({-w, {from, to}});
    }  
    int edges = 0;
    while(!pq.empty()){
        auto edge = pq.top();
        pq.pop();
        int weight = -edge.first;
        int from = edge.second.first;
        int to = edge.second.second;
        if(U._find(from) != U._find(to)){
            U._union(from, to);
            sum += weight;
            edges++;
        }
        if(edges == V - 1){
            break;
        }
    }
    cout << sum;

    return 0;
}