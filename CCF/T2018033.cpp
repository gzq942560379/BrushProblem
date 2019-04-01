//
// Created by guozhuoqiang on 2019-03-16.
//
#include <iostream>
#include <string>
#include <regex>

using namespace std;

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

const int maxN = 101;
const int maxM = 101;

int n, m;

struct Pattern {
    regex re;
    string name;
};

Pattern p[maxN];

bool match(vector<string> &pt, vector<string> &s) {

}

string convertToRegex(string t) {
    vector<string> sp;
    split(t, "/", sp);
    string pattern;
    for (int i = 0; i < sp.size(); i++) {
        string s = sp[i];
        pattern += "/";
        if ("<int>" == s) {
            pattern += "([0-9]+)";
        } else if ("<str>" == s) {
            pattern += "([0-9a-zA-Z\\-_\\.]+)";
        } else if ("<path>" == s) {
            pattern += "([0-9a-zA-Z\\-_\\./]+)";
        } else {
            pattern += s;
        }
    }
    if (t[t.size() - 1] == '/') pattern += "/";
    return pattern;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    string t;
    for (int i = 0; i < n; ++i) {
        cin >> t >> p[i].name;
        t = convertToRegex(t);
        p[i].re = regex(t);
    }
    for (int j = 0; j < m; ++j) {
        cin >> t;
        vector<string> sp;
        split(t, "/", sp);
        int i = 0;
        for (; i < n; i++) {
            if (regex_match(t, p[i].re)) {
                cout << p[i].name << endl;
                break;
            }
        }
        if (i == n) {
            cout << "404" << endl;
        }
    }
    return 0;
}
