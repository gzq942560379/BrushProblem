//
// Created by guozhuoqiang on 2019-03-26.
//
// leetcode 不给过 不知道什么问题
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            char x = s[i - 1];
            for (int j = 1; j <= m; j++) {
                char y = p[j - 1];
                if (y == '*') {
                    char z = p[j - 2];
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (x == z || z == '.'));
                } else {
                    dp[i][j] = (i > 0 && dp[i - 1][j - 1] && (x == y || y == '.'));
                }
            }
        }
        return dp[n][m];
    }
};


int main() {
    Solution s;
    cout << s.isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s");
    return 0;
}