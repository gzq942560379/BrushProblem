//
// Created by guozhuoqiang on 2019-04-27.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findRotateSteps(string ring, string key) {
		int index = 0;
		int m = key.size(), n = ring.size();
		if (m == 0) {
			return 0;
		}
		vector<vector<pair<int, int>>> dp(m, vector<pair<int,int>>());
		//倒排表优化
		vector<vector<int>> invertTable(26, vector<int>());
		for (int i = 0; i < n; i++) {
			invertTable[ring[i] - 'a'].push_back(i);
		}
		// i==0 的情况
		for (int index : invertTable[key[0]-'a']) {
			dp[0].push_back(make_pair(index,min(index,n-index) + 1));
		}
		for (int i = 1; i < m; i++) {
			for (int toIndex : invertTable[key[i]-'a']) {
				int cost = INT_MAX;
				for (const auto& p : dp[i - 1]) {
					int fromIndex = p.first;
					int step = abs(toIndex - fromIndex);
					cost = min(cost, p.second+min(step, n - step) + 1);
				}
				dp[i].push_back(make_pair(toIndex, cost));
			}
		}
		int result = INT_MAX;
		for (auto p : dp[m - 1]) {
			result = min(result, p.second);
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.findRotateSteps("godding", "gd") << endl;
	return 0;
}