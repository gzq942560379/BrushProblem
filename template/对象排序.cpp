//
// Created by guozhuoqiang on 2019-03-10.
//


#include <string>
#include <iostream>
#include <algorithm>
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
    ios::sync_with_stdio(false);
    n = 10;
    for (int i = 0; i < n; ++i) {
        s[i].name = "A"+to_string(i);
        s[i].score = i;
    }

    stable_sort(s,s+n,student_less);
    for (int j = 0; j < n; ++j) {
        cout << s[j].name << " "<< s[j].score << endl;
    }
    cout << endl;
    stable_sort(s,s+n,student_greater);
    for (int j = 0; j < n; ++j) {
        cout << s[j].name << " "<< s[j].score << endl;
    }

    return 0;
}
