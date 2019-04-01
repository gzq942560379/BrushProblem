//
// Created by guozhuoqiang on 2019-03-11.
//

/*
 * N在k进制下表示为 a0 + a1*k^1 + a2*k^2 + ...
 * N' = a0 + a1 + a2 ...
 * N - N' = a1(k-1) + a2(k^2-1) + a3(k^3-1) ...
 * (N - N') % (k-1) == 0
 * 同理
 * (N' - N'') % (k-1) == 0
 * 有
 * (N - Nr)%(k-1) == 0
 *  N%(k-1) = Nr%(k-1)
 *  Nr < k
 *  若 Nr < k-1
 *  Nr%(k-1) = Nr   N%(K-1) = Nr
 *  (x^y)%(k-1) = Nr;
 *  若Nr == k-1 则 N%(k-1) == 0；
 */

#include <iostream>

using namespace std;

int main() {
    int x, y, k;
    long long base, ans;
    while (cin >> x >> y >> k) {
        ans = 1;
        base = x;
        while (y > 0) {
            if ((y & 1) == 1) {
                ans = ans * base % (k - 1);
            }
            base = base * base % (k - 1);
            y >>= 1;
        }
        if(ans == 0) ans = k-1;
        cout << ans << endl;
    }
    return 0;
}
