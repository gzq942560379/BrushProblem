//
// Created by gzq on 4/26/19.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        vector<vector<long long>> dp(m, vector<long long>(n + 1, 0));
        vector<long long> sum(n + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i - 1] + nums[i - 1];
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = INT32_MAX;
                for (int k = i - 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum[j] - sum[k]));
                }
            }
        }
        //返回分割长度为n的数组分割m-1次 各自和的最大值最小
        return dp[m - 1][n];
    }
};

int main() {
    Solution s;
    vector<int> input1{7, 2, 5, 10, 8};
    cout << s.splitArray(input1, 2) << endl;
    vector<int> input2{1, 2147483647};
    cout << s.splitArray(input2, 2) << endl;
    return 0;
}