#include<bits/stdc++.h>
#include <vector>
using namespace std;
using vi = vector<int>;
int pow_i(int x, int y){
    int res = 1;
    while(y--){
        res *= x;
    }
    return res;
}

int rev(int x){
    int res = 0;
    while(x > 0){
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

vi i_to_v(int x){
    vi res;
    while(x){
        res.push_back(x%10);
        x /= 10;
    }
    return vi(res.rbegin(), res.rend());
}

int v_to_i(vi &v){
    int res = 0;
    for(int x: v){
        res = 10 * res + x;
    }
    return res;
}
long long cnt = 0;
int solve(int D){
    int ans = -1;
    for(int k=1;k<=6;k++){
        vi nums(2*k, 0);
        for(int head=pow_i(10, k-1);head<pow_i(10,k);head++){
            vi h = i_to_v(head);
            vi idxs;
            for(int i=0;i<k;i++){
                nums[i] = h[i];
                if(nums[i] == 0){
                    idxs.push_back(2*k-1-i);
                }
            }
            if(idxs.empty()){
                int t = v_to_i(nums);
                if(t - rev(t) == D){
                    ans = t;
                    return ans;
                }
            }
            
            for(int i=0;i<pow_i(10, idxs.size());i++){
                cnt++;
                vi c = i_to_v(i);
                vi d = vi(idxs.size(),0);
                for(auto ci = c.rbegin(), di = d.rbegin(); ci!=c.rend();ci++, di++){
                    *di = *ci;
                }
                for(int i=0;i<idxs.size();i++){
                    nums[idxs[i]] = d[idxs.size()-1-i];
                }
                int t = v_to_i(nums);
                if(t - rev(t) == D){
                    ans = t;
                    return ans;
                }
            }
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    int D;
    cin >> D;
    int ans = solve(D);
    cout << ans << endl;
    cout << cnt;
    return 0;
}