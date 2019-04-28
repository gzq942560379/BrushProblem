//
// Created by gzq on 2019/4/28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int strangePrinter(string s) {
		if (s.empty()) return 0;
		string ss{s[0]};
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != ss.back()) {
				ss.push_back(s[i]);
			}
		}
		int n = ss.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = 0; i < n; i++) dp[i][i] = 1;
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i + len <= n; i++) {
				int j = i + len - 1;
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) +(ss[i] == ss[j]?0:1);
				for (int k = i + 1; k < j; k++) {
					if (ss[i] == ss[k]) {
						dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
					}
				}
			}
		}
		return dp[0][n - 1];
	}	
};

int main() {
	Solution s;
	cout << s.strangePrinter("aaabbb") << endl;
	cout << s.strangePrinter("aba") << endl;

	return 0;
}