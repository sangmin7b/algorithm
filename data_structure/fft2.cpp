#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using cd = complex<double>;
using vc = vector<cd>;

int bit_rev(int x, int n){
    for(int i=0;i<n/2;i++){
        int t = x & (1 << i) ? 1 : 0;
        t ^= (x & (1 << (n - 1 - i)) ? 1 : 0);
        x ^= (t << (n - 1 - i)) | (t << i);
    }
    return x;
}

void bit_rev_permutation(vc &a){
    int n = 0;
    while((1 << n) < a.size()){
        n++;
    }
    for(int i=0;i<a.size();i++){
        int r = bit_rev(i, n);
        if(r < i){
            continue;
        }
        cd t = a[i];
        a[i] = a[r];
        a[r] = t; 
    }
}

void fft(vc &a, bool rev = false){
    double pi = 2*acos(0);
    for(int n=2;n<=a.size();n*=2){
        cd wn = cd(cos(2*pi/n), sin(2*pi/n));
        if(rev){
            wn = cd(1) / wn;
        }
        for(int i=0;i<a.size();i+=n){
            cd w = cd(1);
            for(int j=0;j<n/2;j++){
                cd y1 = a[i+j];
                cd y2 = a[i+j+n/2];
                a[i+j] = y1 + w * y2;
                a[i+j+n/2] = y1 - w * y2;
                w *= wn;
            }
        }
    }
    return;
}

vi conv(vi &a, vi &b){
    int n = 1;
    while(n < a.size() + b.size()){
        n *= 2;
    }
    vc a2(n), b2(n);
    for(int i=0;i<a.size();i++){
        a2[i] = cd(a[i], 0);
    }
    for(int i=0;i<b.size();i++){
        b2[i] = cd(b[i], 0);
    }
    bit_rev_permutation(a2);
    fft(a2);
    bit_rev_permutation(b2);
    fft(b2);
    vc c(n);
    for(int i=0;i<n;i++){
        c[i] = a2[i] * b2[i];
    }
    bit_rev_permutation(c);
    fft(c, true);
    for(int i=0;i<n;i++){
        c[i] /= cd(n);
    }
    vi ans(n);
    for(int i=0;i<n;i++){
        ans[i] = round(c[i].real());
    }
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    vi a, b;
    for(char x:s1){
        a.push_back(x-'0');
    }
    for(char x:s2){
        b.push_back(x-'0');
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vi c = conv(a, b);
    int carry = 0;
    for(int i=0;i<c.size();i++){
        c[i] += carry;
        carry = c[i] / 10;
        c[i] %= 10;
    }
    while(carry){
        c.push_back(carry % 10);
        carry /= 10;
    }
    auto it = c.rbegin();
    while(*it == 0 && it != c.rend()){
        it++;
    }
    if(it == c.rend()){
        cout << 0;
    }
    while(it!=c.rend()){
        cout << *it;
        it++;
    }
    return 0;
}     
