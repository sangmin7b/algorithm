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

vc fft(vc a, bool rev = false){
    int n = a.size();
    vc v(n);
    if(n == 1){
        v[0] = a[0];
        return v;
    }
    vc a1(n/2), a2(n/2);
    for(int i=0;i<n/2;i++){
        a1[i] = a[2*i];
        a2[i] = a[2*i+1];
    }
    vc v1, v2;
    v1 = fft(a1, rev);
    v2 = fft(a2, rev);
    double pi = 2*acos(0);
    cd wn = cd(cos(2*pi/n), sin(2*pi/n));
    if(rev){
        wn = cd(1,0) / wn;
    }
    cd w = cd(1, 0);
    for(int i=0;i<n/2;i++){
        v[i] = v1[i] + w * v2[i];
        v[i+n/2] = v1[i] - w * v2[i];
        w *= wn;
    }
    return v;
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
    vc c1 = fft(a2);
    vc c2 = fft(b2);
    vc c3(n);
    for(int i=0;i<n;i++){
        c3[i] = c1[i] * c2[i];
    }
    vc res = fft(c3, true);
    for(int i=0;i<n;i++){
        res[i] /= cd(n, 0);
    }
    vi ans(n);
    for(int i=0;i<n;i++){
        ans[i] = round(res[i].real());
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
