//
// Created by guozhuoqiang on 2019-03-23.
//
/*
 *
 * 根据空间来进行状态转移，想想有些不合常理，但是却可以解决问题。
 *
 * 虽然坐座位有时间顺序，但四种种空间状态已经包括了所有坐座位的时间顺序
 * 考虑坐第i个座位时会出现四种情况
 * 左右没人  -->  坐i-1座位时右边有人 dp[i-1][2] dp[i-1][3]
 * 左有右无  -->  坐i-1座位时右边没人 dp[i-1][0] dp[i-1][1]
 * 左无右有  -->  坐i-1座位时右边有人 dp[i-1][2] dp[i-1][3]
 * 左右都有  -->  坐i-1座位时右边没人 dp[i-1][0] dp[i-1][1]
 *
 * 只依赖前一行 压缩空间
 *
 * dp[i][0-3] 表示第i个座位被坐时 左右没人 左有右无 左无右有 左右都有四种状态
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 10001;

int n;
int a[maxN], b[maxN], c[maxN];

int now = 1, last = 0;
int dp[2][4];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    dp[last][0] = a[0];
    dp[last][2] = b[0];
    dp[last][1] = dp[0][3] = 0;
    for (int i = 1; i < n; i++, now = 1 - now, last = 1 - last) {
        dp[now][0] = max(dp[last][2], dp[last][3]) + a[i];
        dp[now][1] = max(dp[last][0], dp[last][1]) + b[i];
        dp[now][2] = max(dp[last][2], dp[last][3]) + b[i];
        dp[now][3] = max(dp[last][0], dp[last][1]) + c[i];
    }
    cout << max(dp[last][0], dp[last][1]) << endl;
    return 0;
}

