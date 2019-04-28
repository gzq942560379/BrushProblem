//
// Created by guozhuoqiang on 2019-03-23.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        bool *dp = new bool[n]();
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                if (dp[i + j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }

};

int main() {


    Solution s;
    vector<int> v{3,2,1,0,4};
    cout << s.canJump(v);

    return 0;
}