//
// Created by guozhuoqiang on 2019-03-29.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int mx = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        return mx;
    }
};

int main() {

    vector<vector<char>> v{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

    vector<vector<char>> v2{
            {'0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };
    Solution s;
    cout << s.maximalRectangle(v2);

    return 0;
}

