//
// Created by gzq on 2019/4/29.
//
#include <iostream>
#include <vector>
#include <algorithm>

// DP 自顶向下 记忆化动规
using namespace std;

class Solution {
public:
	// 两个人同时走
	static const int maxN = 50;
	int dp[2][maxN][maxN];
	int N;
	int cur = 0;

	int cherryPickup(vector<vector<int>>& grid) {
		N = grid.size();
		//init
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[cur][i][j] = INT_MIN;
		dp[cur][0][0] = grid[0][0] == 1 ? 1 : 0;
		cur = 1 - cur;
		int total_step = 2 * N - 2;
		for (int t = 1; t <= total_step; t++,cur = 1 - cur) {
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[cur][i][j] = INT_MIN;
			for (int r1 = max(0, t - N + 1); r1 <= min(t, N - 1); r1++) {
				for (int r2 = max(0, t - N + 1); r2 <= min(t, N - 1); r2++) {
					if (grid[r1][t - r1] == -1 || grid[r2][t - r2] == -1) {
						continue;
					}
					int val = grid[r1][t - r1] + (r1 == r2 ? 0 : grid[r2][t - r2]);

					dp[cur][r1][r2] = max(dp[cur][r1][r2], dp[1 - cur][r1][r2] + val);
					if(r1>0) dp[cur][r1][r2] = max(dp[cur][r1][r2], dp[1 - cur][r1-1][r2] + val);
					if(r2>0) dp[cur][r1][r2] = max(dp[cur][r1][r2], dp[1 - cur][r1][r2-1] + val);
					if(r1>0 && r2>0) dp[cur][r1][r2] = max(dp[cur][r1][r2], dp[1 - cur][r1-1][r2-1] + val);
				}
			}
		}
		return max(0,dp[1 - cur][N - 1][N - 1]);
	}
};

int main() {
	Solution s;
	vector<vector<int>> input1{ {0, 1, -1},{1, 0, -1},{1, 1,  1} };
	cout << s.cherryPickup(input1) << endl;
}
 