//
// Created by guozhuoqiang on 2019-03-10.
//
#include <string>
#include <iostream>
#include <algorithm>
//#define F
#ifdef F
#include <fstream>
#endif

using namespace std;

struct Student{
    string name;
    int score;
};

bool student_less(const Student & s1,const Student & s2){
    return s1.score < s2.score;
}

bool student_greater(const Student & s1,const Student & s2){
    return s1.score > s2.score;
}


const int maxN = 1000000;

int n;
int t;

Student s[maxN];

int main(){
#ifdef F
        ifstream fin("../../data/qinghua/成绩排序.in");
        cin.rdbuf(fin.rdbuf());
#endif
    ios::sync_with_stdio(false);
    while (cin >> n >> t){
        for (int i = 0; i < n; ++i) {
            cin >> s[i].name;
            cin >> s[i].score;
        }
        if(t == 1){
            stable_sort(s,s+n,student_less);
        }else{
            stable_sort(s,s+n,student_greater);
        }
        for (int j = 0; j < n; ++j) {
            cout << s[j].name << " "<< s[j].score << endl;
        }
    }
    return 0;
}
