//
// Created by gzq on 2019/4/28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	const int MOD = 1000000007;
    int numDecodings(string s) {
		int n = s.size();
		vector<long long> dp(n+1);
		dp[0] = 1;
		dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0: 1;
		for (int i = 2; i <= n; i++) {
			char cur = s[i-1], prev = s[i-2];
			long long val;
			if (cur == '*') {
				val = (9 * dp[i-1])%MOD;
				if (prev == '1') {
					val = (val + 9 * dp[i - 2]) % MOD;
				}else if(prev == '2') {
					val = (val + 6 * dp[i - 2]) % MOD;
				}else if (prev == '*') {
					val = (val + 15 * dp[i - 2]) % MOD;
				}
			}
			else {
				val = cur == '0' ? 0 : (dp[i - 1]) % MOD;
				if (prev == '1') {
					val = (val + dp[i - 2]) % MOD;
				}
				else if (prev == '2' && cur <= '6') {
					val = (val + dp[i - 2]) % MOD;
				}
				else if (prev == '*') {
					val = (val + (cur <= '6' ? 2 : 1) * dp[i - 2]) % MOD;
				}
			}
			dp[i] = val;
		}
		return dp[n];
	}
};

int main(){
	Solution s;
	cout << s.numDecodings("204") << endl;
	cout << s.numDecodings("2839") << endl;
	cout << s.numDecodings("*1") << endl;
	cout << s.numDecodings("*") << endl;
	cout << s.numDecodings("1*") << endl;
	cout << s.numDecodings("0") << endl;
	return 0;
}
