//
// Created by guozhuoqiang on 2019-03-23.
//
#include <iostream>

#include <vector>


using namespace std;

class Solution {
public:


    //  O(n*log(n))实现
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            int u = nums[i];
            int top = v[v.size() - 1];
            if (u > top) {
                v.push_back(u);
            } else {
                int index = lower_bound(v.begin(), v.end(), u) - v.begin();
                v[index] = u;
            };
        }
        return v.size();
    }

    //  O(n^2)实现
    int lengthOfLIS2(vector<int> &nums) {
        int n = nums.size();
        int *dp = new int[n + 1];
        dp[0] = 0;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            for (int j = 1; j < i; j++) {
                if (nums[i - 1] > nums[j - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(dp[i], mx);
        }
        return mx;
    }

};


int main() {
    Solution s;
    vector<int> v{10, 9, 2, 5, 3, 4};
    cout << s.lengthOfLIS(v);
    return 0;
}