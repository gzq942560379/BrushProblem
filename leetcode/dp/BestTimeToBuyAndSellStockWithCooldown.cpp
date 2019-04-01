//
// Created by guozhuoqiang on 2019-03-23.
//
#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int buy = -prices[0], sell = 0, lastBuy = 0, lastSell = 0;
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            lastBuy = buy;
            buy = max(lastSell - p, lastBuy);
            lastSell = sell;
            sell = max(lastBuy + p, lastSell);
        }
        return sell;
    }
};

int main() {

    Solution s;
    vector<int> v{1, 2, 3, 0, 2};
    cout << s.maxProfit(v);

    return 0;
}
