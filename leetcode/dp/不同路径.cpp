//
// Created by guozhuoqiang on 2019-03-23.
//
#include <iostream>


class Solution {
public:
    int dp[100];
    int uniquePaths(int m, int n) {
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    std::cout << s.uniquePaths(23, 12);
    return 0;
}