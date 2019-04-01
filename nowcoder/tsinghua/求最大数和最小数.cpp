//
// Created by guozhuoqiang on 2019-03-11.
//

#include <iostream>

const int INF = 1000001;
const int NINF = -1000001;

using namespace std;

int main() {
    int mx, mi, n;
    int t;
    while (cin >> n) {
        mx = NINF;
        mi = INF;
        for (int i = 0; i < n; ++i) {
            cin >> t;
            mx = max(mx, t);
            mi = min(mi, t);
        }
        cout << mx << " " << mi << endl;
    }

    return 0;
}
