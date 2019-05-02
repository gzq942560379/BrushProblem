//
// Created by guozhuoqiang on 2019-03-24.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        int n = s.size();
        bool **dp = new bool *[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new bool[n];
        }
        for (int i = 0; i < n; i++)dp[i][i] = true;
		for (int i = 1; i < n; i++)
			if (s[i - 1] == s[i])
				dp[i - 1][i] = true;
			else
				dp[i - 1][i] = false;

        for (int l = 3; l <= n; l++) {
            for (int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }
        }
        for (int len = n; len > 0; len--) {
            for (int ll = 0; ll + len <= n; ll++) {
                if (dp[ll][ll + len - 1])
                    return s.substr(ll, len);
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("cbbd");
    return 0;
}