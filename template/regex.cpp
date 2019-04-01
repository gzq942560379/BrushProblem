//
// Created by guozhuoqiang on 2019-03-16.
//
#include <string>
#include <regex>
#include <iostream>
#include <vector>

using namespace std;

void match() {
    string s = "201711170700";
    regex pattern("([0-9]{4})([0-9]{2})([0-9]{2})([0-9]{2})([0-9]{2})");
    smatch r;
    if (regex_match(s, r, pattern)) {
        cout << "match !!!" << endl;
        for (int i = 0; i < r.size(); ++i) {
            ssub_match sm = r[i];
            string s = sm.str();
            cout << s << endl;
        }
    }
}


//正则match_search 实现split 自动过滤空字符串
void split(string input, string pattern, vector<string> &ret) {
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

int main() {
    match();
    string aa = "a.b c";
    vector<string> ret;
    split(aa, "\\.", ret);
    for (string s:ret) {
        cout << s << endl;
    }
    return 0;
}