//
// Created by gzq on 2019/4/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int minStickers(vector<string>& stickers, string target) {
		int n = target.size();
		int N = 1 << n;
		vector<int> dp(N, -1);
		dp[0] = 0;
		for (int state = 0; state < N; state++) {
			if (dp[state] == -1) continue;
			for (const string& sticker : stickers) {
				int now = state;
				for (const char latter : sticker) {
					for (int i = 0; i < n; i++) {
						if ((now >> i) & 1 == 1) continue;
						if (latter == target[i]) {
							now |= 1 << i;
							break;
						}
					}
				}
				if (dp[now] == -1 || dp[now] > dp[state] + 1) {
					dp[now] = dp[state] + 1;
				}
			}
		}
		return dp[N - 1];
	}
};


int main() {
	Solution s;
	vector<string> input1{ "with", "example", "science" };
	cout << s.minStickers(input1, "thehat") << endl;
	return 0;
}