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
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int k = 2;
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};

int main() {
    Solution s;
    vector<int> v{3, 2, 6, 5, 0, 3};
    cout << s.maxProfit( v);
    return 0;
}