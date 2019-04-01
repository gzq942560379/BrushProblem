//
// Created by guozhuoqiang on 2019-03-29.
//
#include <iostream>

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), w = s3.size();
        if (m + n != w) {
            return false;
        }
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = (i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) ||
                           (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) ||
                           (i == 0 && j == 0);
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc");
    cout << s.isInterleave("", "", "a");

    return 0;
}