#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> nums;
vector<vector<ll>> DP;
vector<int> inv;
int N, M, K;
ll gcd(ll a, ll b){
    if(a < b){
        return gcd(b, a);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

vector<int> ll_to_set(ll S){
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        if(!(S & (1LL << i))){
            res.push_back(i);
        }
    }
    return res;
}

int s_to_i(string s){
    int res = 0;
    for(int i=0;i<s.length();i++){
        res *= 10;
        res += s[i] - '0';
        res %= K;
    }
    return res;
}

vector<int> idx_to_i;
vector<int> idx_to_l;
vector<ll> fact;
int Kpow(int l){
    int exp = 1;
    for(int i=0;i<l;i++){
        exp *= 10;
        exp %= K;
    }  
    return exp;   
}


ll f(ll S, int T, int E){
    if(DP[S][T] != -1){
        return DP[S][T];
    }
    vector<int> s = ll_to_set(S);    

    if(s.size() == 0){
        if(T == 0){
            DP[S][T] = 1;
            return 1;
        }else{
            DP[S][T] = 0;
            return 0;
        }
    }
    ll ans = 0;
    for(int i:s){
        ll next = S | (1LL<<i);
        int T_next = (T + idx_to_i[i] * E) % K;
        int exp = idx_to_l[i];
        ans += f(next, T_next % K, E * exp % K);
    }
    DP[S][T] = ans;
    return ans;    
   
}

int main(int argc, const char** argv) {
    cin >> N;
    for(int i=0;i<N;i++){
        string x; cin >> x;
        nums.push_back(x);
    }
    cin >> K;
    inv = vector<int>(K,-1);
    for(int i=1;i<K;i++){
        for(int j=1;j<K;j++){
            if(i * j % K == 1){
                inv[i] = j;
                break;
            }
        }
    }
    DP = vector<vector<ll>>(1 << N, vector<ll>(K, -1));
    idx_to_i = vector<int>(N, 0);
    idx_to_l = vector<int>(N, 0);
    fact = vector<ll>(51, 1);
    for(ll i=1;i<51;i++){
        fact[i] = fact[i-1] * i;
    }

    for(int i=0;i<nums.size();i++){
        idx_to_i[i] = s_to_i(nums[i]);
        idx_to_l[i] = Kpow(nums[i].length());
    }

    ll all_cases = 1;
    for(ll i=1;i<=N;i++){
        all_cases *= i;
    }
    ll ans = f(0,0,1);
    if(ans == 0){
        cout << "0/1";
    }else{
        cout << ans/gcd(ans,all_cases) << "/" << all_cases / gcd(ans, all_cases) << "\n";
        //cout << ans << "/" << all_cases;
    }
    return 0;
}