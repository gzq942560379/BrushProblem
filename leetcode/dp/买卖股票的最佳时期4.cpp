//
// Created by gzq on 4/2/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n < 2 || k < 1)return 0;
        // 退化为问题二
        if (k >= n / 2)return getMax(prices);
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 1; j <= k; ++j) {
                //对于前i个商品，买卖最多j次可获得的最大利润
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }

private:
    int getMax(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1])
                res += (prices[i] - prices[i - 1]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v{3, 2, 6, 5, 0, 3};
    cout << s.maxProfit(2, v);
    return 0;
}