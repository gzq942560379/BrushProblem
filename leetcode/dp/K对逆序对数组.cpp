//
// Created by guozhuoqiang on 2019-04-27.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
	const int M = 1000000007;
	// O(n*k) 累积和优化
	int kInversePairs(int n, int k) {
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		for (int j = 0; j <= k; j++) dp[0][j] = 0;
		for (int i = 1; i <= n; i++) dp[i][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				int val = (dp[i - 1][j] + M - (j >= i ? dp[i - 1][j - i] : 0)) % M;
				dp[i][j] = (dp[i][j - 1] + val) % M;
			}
		}
		return  ((dp[n][k] + M - (k > 0 ? dp[n][k - 1] : 0)) % M);
	}


	// O(n^2*k)
	/*
	int kInversePairs(int n, int k) {
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		for (int j = 0; j <= k; j++)      dp[0][j] = 0;
		for (int i = 1; i <= n; i++)      dp[i][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				//p为为补齐j逆序对要新增的逆序对数 所以有 j>p
				//添加一个i最多加i-1个逆序对
				for (int p = 0; p <= min(j, i - 1); p++)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % M;
			}
		}
		return dp[n][k];
	}
	*/
};

int main() {
	Solution s;
	cout << s.kInversePairs(3, 1) << endl;
	return 0;
}