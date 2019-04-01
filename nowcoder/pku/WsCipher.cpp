//
// Created by guozhuoqiang on 2019-03-19.
//
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int k[3];

const int maxL = 81;

vector<int> pos[3];
char str[3][maxL];
char ll[3];

int main() {
    ios::sync_with_stdio(false);
    char s[maxL];
    while (true) {
        cin >> k[0] >> k[1] >> k[2];
        if (k[0] == 0 && k[1] == 0 && k[2] == 0) {
            break;
        }
        cin >> s;
        int ls = strlen(s);
        for (int i = 0; i < 3; i++) {
            pos[i].clear();
            ll[i] = 0;
        }
        for (int i = 0; i < ls; i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'i') {
                pos[0].push_back(i);
                str[0][ll[0]++] = c;
            } else if (c >= 'j' && c <= 'r') {
                pos[1].push_back(i);
                str[1][ll[1]++] = c;
            } else if ((c >= 's' && c <= 'z') || c == '_') {
                pos[2].push_back(i);
                str[2][ll[2]++] = c;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < ll[i]; j++) {
                s[pos[i][(j + k[i]) % ll[i]]] = str[i][j];
            }
        }
        cout << s << endl;
    }
    return 0;
}
