#include<bits/stdc++.h>

using namespace std;
struct student{
    string name;
    int score[3];
    student(string s, int _a, int _b, int _c){
        name = s;
        score[0] = _a;
        score[1] = _b;
        score[2] = _c;
        
    };
};

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<student> s;
    for(int i=0;i<N;i++){
        string n;
        int score[3];
        cin >> n;
        cin >> score[0] >> score[1] >> score[2];
        s.push_back(student(n, score[0], score[1], score[2]));
    }

    function<bool(student, student)> cmp = [](student s1, student s2){
        if(s1.score[0] != s2.score[0]){
            return s1.score[0] > s2.score[0];
        }
        if(s1.score[1] != s2.score[1]){
            return s1.score[1] < s2.score[1];
        }
        if(s1.score[2] != s2.score[2]){
            return s1.score[2] > s2.score[2];
        }
        return s1.name < s2.name;
    };
    sort(s.begin(), s.end(), cmp);
    for(student st: s){
        cout << st.name << "\n";
    }
    return 0;
}