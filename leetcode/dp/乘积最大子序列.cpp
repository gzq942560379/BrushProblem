//
// Created by guozhuoqiang on 2019-03-23.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        int dp_min, dp_max, temp;
        int mx = dp_min = dp_max = nums[0];
        for (int i = 1; i < n; i++) {
            int u = nums[i];
            if (u >= 0) {
                dp_max = max(u, u * dp_max);
                dp_min = min(u, u * dp_min);
            } else {
                temp = dp_max;
                dp_max = max(u, u * dp_min);
                dp_min = min(u, u * temp);
            }
            mx = max(dp_max, mx);
        }
        return mx;
    }
};


int main() {
    Solution s;
    vector<int> v{2, 3, -2, 4};
    cout << s.maxProduct(v);
    return 0;
}
