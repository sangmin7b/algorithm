#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    // transposed DNA
    vector<vector<char>> DNA(M,vector<char>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> DNA[j][i];
        }
    }
    vector<char> codes = {'A', 'C', 'G', 'T'};
    vector<pii> ans;
    auto counts = [=](vector<char> &s){
        vector<int> result;
        transform(codes.begin(), codes.end(),
        back_inserter(result),
        [=](char x){return count(s.begin(), s.end(), x);});
        auto it = max_element(result.begin(), result.end());
        return pii{distance(result.begin(), it), *it};
    };
    transform(DNA.begin(), DNA.end(), back_inserter(ans),
        [=](vector<char> &s){return counts(s);});
    for(auto a: ans){
        cout << codes[a.first];
    }
    cout << "\n";
    cout << N * M - transform_reduce(ans.begin(), ans.end(), 0, plus<>{}, [](pii p){return p.second;});
    return 0;
}