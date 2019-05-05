#include <utility>

//
// Created by gzq on 5/5/19.
//
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

// dfa 依赖字符集 大写字母
class KMA {


public:

    KMA(const string &pattern) : pattern(pattern) {
        M = pattern.size();
        if (M == 0)
            return;
        dfa = vector<vector<int>>(CHARSET_SIZE, vector<int>(M, 0));
        dfa[index(pattern[0])][0] = 1;
        for (int X = 0, j = 1; j < M; j++) {
            for (int i = 0; i < CHARSET_SIZE; i++) {
                dfa[i][j] = dfa[i][X];
            }
            dfa[index(pattern[j])][j] = j + 1;
            X = dfa[index(pattern[j])][X];
        }
    };

    int search(const string &txt) const {
        int N = txt.size();
        int i = 0, j = 0;
        for (; i < N && j < M; i++) {
            j = dfa[index(txt[i])][j];
        }
        return j == M ? i - M : -1;
    };

private:
    inline int index(char ch) const {
        if (ch < 'A' || ch > 'Z')
            throw std::invalid_argument("charset only for A-Z!!!");
        return ch - 'A';
    }

    int M;
    string pattern;
    vector<vector<int>> dfa;
    static const int CHARSET_SIZE = 26;
};

int main() {
    KMA kma("ABABAC");
    std::cout << kma.search("BCBAABACAABABACAA") << std::endl;

}