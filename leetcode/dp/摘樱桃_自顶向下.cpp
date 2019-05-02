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
	int memo[maxN][maxN][maxN];
	int N;

	int dp(vector<vector<int>>& grid,int r1,int c1,int r2){
		int c2 = r1 + c1 - r2;
		//边界与-1
		if (N == r1 || N == c1 || N == r2 || N == c2 || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
			return INT_MIN;
		}
		//初始条件
		else if (r1 == N - 1 && c1 == N - 1) {
			return grid[r1][c1];
		}
		//已访问
		else if (memo[r1][c1][r2] != INT_MIN) {
			return memo[r1][c1][r2];
		}
		else {
			int ans = grid[r1][c1];
			if (r1 != r2) ans += grid[r2][c2];
			ans += max(
				max(dp(grid, r1 + 1, c1 ,r2 + 1), dp(grid, r1 + 1, c1, r2)),
				max(dp(grid, r1, c1 + 1, r2 + 1), dp(grid, r1, c1 + 1, r2))
			);
			memo[r1][c1][r2] = ans;
			return ans;
		}
	}

	int cherryPickup(vector<vector<int>>& grid) {
		N = grid.size();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					memo[i][j][k] = INT_MIN;
				}
			}
		}
		return max(0, dp(grid, 0, 0, 0));
	}
};

int main() {
	Solution s;
	vector<vector<int>> input1{ {0, 1, -1},{1, 0, -1},{1, 1,  1} };
	cout << s.cherryPickup(input1) << endl;
}
 