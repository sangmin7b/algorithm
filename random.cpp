#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_int_distribution<int> distribution (1,6);
    for(int i=0;i<N;i++){
        int dice_roll = distribution(gen);
        cout << dice_roll << "\n";
    }
    return 0;
}