#include<bits/stdc++.h>

using namespace std;
int main(int argc, const char** argv) {
    int N, F;
    cin >> N >> F;
    int head = (N / 100) * 100;
    int tail = 0;
    while(tail < 100){
        if ((head + tail) % F == 0){
            break;
        } 
        tail++;
    }
    cout << tail / 10 << tail % 10;
    return 0;
}