#include <bits/stdc++.h>
using pi = pair<int, int>;

bool is_inside(pi p, int N, int M){
    return 0 <= p.first && p.first < N && 0 <= p.second && p.second < M; 
}