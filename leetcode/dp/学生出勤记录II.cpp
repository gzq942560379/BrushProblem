//
// Created by guozhuoqiang on 2019-04-27.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>

using namespace std;

// TODO 空间不足

class Solution {
public:
	const static int maxN = 10001;
	const static int MOD = 1000000007;
	int dp[maxN][2][3];
	int checkRecord(int n) {	
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				dp[0][j][k] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 3; k++) {
					int val = dp[i - 1][j][2];
					if (j > 0) 
						val = (val + dp[i - 1][j - 1][2]) % MOD;
					if (k > 0) 
						val = (val + dp[i - 1][j][k - 1]) % MOD;
					dp[i][j][k] = val;
				}
			}
		}
		return dp[n][1][2];
	}
};

int main() {
	Solution s;
	cout << s.checkRecord(2) << endl;
	cout << s.checkRecord(3) << endl;
	return 0;
}