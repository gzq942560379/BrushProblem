//
//  main.cpp
//  split
//
//  Created by guozhuoqiang on 06/03/2019.
//  Copyright © 2019 guozhuoqiang. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

const int maxL = 81;
const int maxN = 101;

//原s已被修改   危险 不建议使用
void split1(char *s, char *d, vector<char *> &ret) {
    char *t = strtok(s, d);
    while (t) {
        ret.push_back(t);
        t = strtok(NULL, d);
    }
}

//推荐使用
void split2(string s, string d, vector<string> &ret) {
    int p = 0, pp;
    string t;
    while ((pp = s.find(d, p)) != string::npos) {
        t = s.substr(p, pp - p);
        if (!t.empty()) ret.push_back(t);
        p = pp + d.size();
    }
    pp = s.size();
    t = s.substr(p, pp - p);
    if (!t.empty()) ret.push_back(t);
}


//正则match_search 实现split 自动过滤空字符串
void split3(string input, string pattern, vector<string> &ret) {
    string &s = input;
    regex re(pattern);
    smatch sm;
    while (regex_search(s, sm, re)) {
        string str = sm.prefix().str();
        if (!str.empty()) ret.push_back(str);
        s = sm.suffix();
    }
    if (!s.empty()) ret.push_back(s);
}

int main(int argc, const char *argv[]) {
    int n;
    cin >> n;
    string sin;
    getline(cin,sin);
    while (n--){
        getline(cin,sin);
        vector<string> ret;
        split2(sin, " ", ret);
        for (const string &s:ret) {
            cout << s << endl;
        }
    }
    return 0;
}
