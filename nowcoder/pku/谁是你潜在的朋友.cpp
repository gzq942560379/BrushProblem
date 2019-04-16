//
// Created by guozhuoqiang on 2019-03-19.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxMN = 201;

int n, m, r;
int like[maxMN];
int belike[maxMN];

int main() {
    ios::sync_with_stdio(false);


    while (cin >> n >> m) {
        fill(belike, belike + m + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> like[i];
            belike[like[i]] += 1;
        }
        for (int i = 1; i <= n; i++) {
            r = belike[like[i]] - 1;
            if (r) {
                cout << r << endl;
            } else {
                cout << "BeiJu" << endl;
            }
        }
    }
    return 0;
}

