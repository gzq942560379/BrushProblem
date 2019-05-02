//
// Created by guozhuoqiang on 2019-03-23.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long dp[100][100];

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid.front().size();
		dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
		for (int i = 1; i < n; i++) {
			dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
		}
		for (int i = 1; i < m; i++) {
			dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				}else{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main() {
    Solution s;
	vector<vector<int>> input1{ {0,0,0},{0,1,0},{0,0,0} };
	cout << s.uniquePathsWithObstacles(input1) << endl;
	vector<vector<int>> input2{ {0,0} };
	cout << s.uniquePathsWithObstacles(input2) << endl;

    return 0;
}