//
// Created by guozhuoqiang on 2019-03-11.
//
#include <iostream>

using namespace std;

const int maxL = 10000000;

int ans[maxL];
int len;
int c;

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        ans[0] = 1;
        len = 1;
        for (int i = 2; i <= n; i++) {
            c = 0;
            for (int j = 0; j < len; j++) {
                c = ans[j] * i + c;
                ans[j] = c % 10;
                c /= 10;
            }
            while (c != 0) {
                ans[len++] = c % 10;
                c /= 10;
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}