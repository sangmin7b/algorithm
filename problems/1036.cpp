#include<bits/stdc++.h>
#include <vector>
class base36;
using namespace std;
using pbi = pair<base36, int>;

void calc_carry(vector<int> &v){
    int carry = 0;
    for(auto it=v.begin();it!=v.end();it++){
        *it += carry;
        carry = *it / 36;
        *it %= 36;
    }
    while(carry){
        v.push_back(carry % 36);
        carry /= 36;
    }
    for(int i=v.size()-1;i>0;i--){
        if(v[i] != 0){
            break;
        }
        v.erase(v.begin() + i);
    }
}

class base36{
public:
    vector<int> data;
    base36(string s){
        for(char c: string(s.rbegin(), s.rend())){
            if('0' <= c && c <= '9')
                data.push_back(c-'0');
            else
                data.push_back(c-'A'+10);
        }
    }
    base36(): data(1,0){}
    base36(int n){
        data = vector<int>();
        do{
            data.push_back(n % 36);
            n /= 36;
        }while(n);
    }    
    base36 operator+ (const base36 &a){
        base36 res;
        res.data = vector<int>();
        auto it1 = data.begin();
        auto it2 = a.data.begin();
        while(it1 != data.end() && it2 != a.data.end()){
            res.data.push_back(*it1 + *it2);
            it1++; 
            it2++;
        }
        while(it1 != data.end()){
            res.data.push_back(*it1);
            it1++;
        }
        while(it2 != a.data.end()){
            res.data.push_back(*it2);
            it2++;
        }
        calc_carry(res.data);
        return res;
    }

    base36 operator*(const base36 &a){
        base36 res;
        res.data = vector<int>(data.size() + a.data.size() - 1, 0);
        for(int i=0;i<data.size();i++){
            for(int j=0;j<a.data.size();j++){
                res.data[i+j] += data[i] * a.data[j]; 
            }
        }
        calc_carry(res.data);
        return res;
    }

    bool operator> (const base36 &a){
        if(data.size() != a.data.size()){
            return data.size() > a.data.size();
        }
        for(int i=data.size()-1;i>=0;i--){
            if(data[i] > a.data[i]){
                return true;
            }
            if(data[i] < a.data[i]){
                return false;
            }
        }
        return false;
    }

    bool operator== (const base36 &a){
        if(data.size() != a.data.size()){
            return false;
        }
        for(int i=data.size()-1;i>=0;i--){
            if(data[i] != a.data[i]){
                return false;
            }
        }
        return true;
    }

    bool operator!=(const base36 &a){
        return !(*this == a);
    }

    base36& operator= (const base36 &a){
        vector<int> tmp(a.data.size());
        for(int i=0;i<a.data.size();i++){
            tmp[i] = a.data[i];
        }
        this->data = tmp;
        return *this;
    }

    void print(){
        for(auto it=data.rbegin();it!=data.rend();it++){
            if(*it < 10){
                cout << (char)(*it + '0');
            }else{
                cout << (char)(*it - 10 + 'A');
            }
        }
    }
};

int main(int argc, const char** argv){
    int N;
    cin >> N;
    vector<base36> cnt(36, base36(0));
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        base36 r(1);
        for(char c: string(s.rbegin(), s.rend())){
            if('0'<= c && c <= '9'){
                c = c - '0';
            }else{
                c = c - 'A' + 10;
            }
            cnt[c] = cnt[c] + r;
            r = r * base36(36);
        }
    }
    int K; cin >> K;
    vector<pbi> sorted;
    for(int i=0;i<36;i++){
        sorted.push_back({cnt[i], i});
    }
    sort(sorted.begin(), sorted.end(), [](pbi &a, pbi &b){
        if(a.first * base36(35 - a.second) == b.first * base36(35 -b.second)){
            return a.second < b.second;
        }else{
            return a.first * base36(35 - a.second) > b.first * base36(35 -b.second);
        }
    });
    base36 ans(0);
    for(int i=0;i<K && i<36;i++){
        ans = ans + sorted[i].first * base36("Z");
    }
    for(int i=K;i<36;i++){
        ans = ans + sorted[i].first * base36(sorted[i].second);
    }
    ans.print();    
    return 0;
}