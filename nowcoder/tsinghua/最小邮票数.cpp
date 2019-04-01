//
// Created by guozhuoqiang on 2019-03-11.
//

#include <iostream>

using namespace std;

const int maxL = 100;
const int INF = 1000000000;

int dp[maxL + 1];
int w[maxL + 1];
int V;
int n;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> V >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
        }
        fill(dp, dp + V + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int v = V; v >= w[i]; v--) {
                dp[v] = min(dp[v - w[i]] + 1, dp[v]);
            }
        }
        cout << (dp[V] < INF ? dp[V] : 0) << endl;
    }
    return 0;
}

