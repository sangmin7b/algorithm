#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int N, M;
vector<vector<bool>> visited;
vector<vector<bool>> _map;

bool is_inside(pii p){
    return 0 <= p.first && p.first < N && 0 <= p.second && p.second < M;
}

void dfs(pii p, vector<pii> &component){
    visited[p.first][p.second] = 1;
    component.push_back(p);
    for(pii dp: {pii{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
        pii next = {p.first + dp.first, p.second + dp.second};
        if(!is_inside(next) || visited[next.first][next.second] || _map[next.first][next.second])
            continue;
        dfs(next, component);            
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    
    cin >> N >> M;
    _map = vector<vector<bool>>(N, vector<bool>(M,0));
    vector<vector<int>> count (N, vector<int>(M, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char x; cin >> x;
            _map[i][j] = x - '0';
        }
    }
    visited = vector<vector<bool>>(N, vector<bool>(M,0));    
    int cnt = 1;
    vector<int> size(1, 0);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j] || _map[i][j])
                continue;
            vector<pii> component;
            dfs({i,j}, component);
            size.push_back(component.size());
            for(auto p: component){
                count[p.first][p.second] = cnt;
            }
            cnt++;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!_map[i][j]){
                cout << 0; 
                continue;
            }
            set<int> adj;
            for(pii dp: {pii{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
                pii next = {i + dp.first, j + dp.second};
                if(!is_inside(next))
                    continue;
                adj.insert(count[next.first][next.second]);
            }
            int sum = 1;
            for(int component_num: adj){
                sum += size[component_num];
            }
            sum %= 10;
            cout << sum;
        }
        cout << "\n";
    }
    return 0;
}