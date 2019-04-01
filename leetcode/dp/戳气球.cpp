//
// Created by guozhuoqiang on 2019-03-24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        if (nums.empty())
            return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n);
        for_each(dp.begin(), dp.end(), [n](vector<int> &v) { v.resize(n, 0); });
        for (int l = 2; l < n; ++l) {
            for (int i = 0; i + l < n; i++) {
                int temp = nums[i] * nums[i + l];
                for (int k = i + 1; k < i + l; ++k) {
                    dp[i][i + l] = max(dp[i][i + l], dp[i][k] + dp[k][i + l] + nums[k] * temp);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {

    Solution s;
    vector<int> v{3, 1, 5, 8};
    cout << s.maxCoins(v);
    return 0;
}