//
// Created by guozhuoqiang on 2019-03-23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    const int INF = 1 << 30;

    int coinChange(vector<int> &coins, int amount) {
        int *dp = new int[amount + 1];
        for (int i = 0; i <= amount; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            int w = coins[i];
            for (int j = w; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - w] + 1);
            }
        }
        return dp[amount] < INF ? dp[amount] : -1;
    }
};

int main() {
    Solution s;
    vector<int> v{2};
    int amount{3};
    cout << s.coinChange(v, amount);
    return 0;
}