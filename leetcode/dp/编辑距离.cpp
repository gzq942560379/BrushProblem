//
// Created by guozhuoqiang on 2019-03-29.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    const int INF = 1 << 30;

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 0; i <= n; i++) dp[0][i] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int flag = word1[i - 1] == word2[j - 1] ? 0 : 1;
                dp[i][j] = INF;
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + flag);
            }
        }
        return dp[m][n];
    }

};

int main() {

    Solution s;

    cout << s.minDistance("intention", "execution");

    return 0;
}
