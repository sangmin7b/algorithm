#include<bits/stdtr1c++.h>

using namespace std;

int main(int argc, const char** argv) {
    int N, M;
    cin >> N;
    int Bmax = 1000000000;
    vector<int> budget;
    for(int i=0;i<N;i++){
        int b;
        cin >> b;
        budget.push_back(b);
    }
    cin >> M;

    function<int(int)> sum_with_limit = [&](int limit){
        int sum = 0;
        for(int b: budget){
            sum += min(b, limit);
        }
        return sum;
    };
    int low = 0;
    int high = Bmax;
    int max_sum = 0;
    while(low < high){
        int mid = (low + high + 1) / 2;
        int l_sum = sum_with_limit(mid);
        if(l_sum > M){
            high = mid-1;
        }else{
            low = mid;
        }        
    }
    int limit = low;
    cout << min(*max_element(budget.begin(), budget.end()), limit);
    return 0;
}