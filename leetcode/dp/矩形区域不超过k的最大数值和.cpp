//
// Created by gzq on 4/24/19.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// TODO 没做出来 以后再做

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ret = -10000000;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j];
                if (i > 0) {
                    int temp = dp[i - 1][j];
                    for (int k = 0; k <= j; k++) {
                        temp += matrix[i][k];
                    }
                    dp[i][j] = max(dp[i][j], temp);
                }
                if (j > 0) {
                    int temp = dp[i][j - 1];
                    for (int k = 0; k <= i; k++) {
                        temp += matrix[k][j];
                    }
                    dp[i][j] = max(dp[i][j], temp);
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> input{{1, 0,  1},
                              {0, -2, 3}};
    int k = 2;
    cout << s.maxSumSubmatrix(input, k) << endl;
    return 0;
}