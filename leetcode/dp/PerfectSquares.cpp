//
// Created by guozhuoqiang on 2019-03-23.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        int sq = 1, i = 1;
        while (sq <= n) {
            squares.push_back(sq);
            i++;
            sq = i * i;
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int square : squares) {
            for (int i = square; i <= n; i++) {
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }
        return dp[n];
    }
};


int main() {
    Solution s;
    cout << s.numSquares(1);
    return 0;
}