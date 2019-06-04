//
// Created by gzq on 6/4/19.
//
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

	bool same(const vector<int>& v1, const vector<int>& v2) {
		int n = v1.size();
		for (int i = 0; i < n; i++) {
			if (v1[i] != v2[i])
				return false;
		}
		return true;
	}

	bool reverse(const vector<int>& v1, const vector<int>& v2) {
		int n = v1.size();
		for (int i = 0; i < n; i++) {
			if (v1[i] == v2[i])
				return false;
		}
		return true;
	}
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		int l = matrix.size();
		int ans = 0;
		for (int i = 0; i < l; i++) {
			int tmp = 0;
			for (int j = 0; j < l; j++) {
				if (same(matrix[i], matrix[j]) || reverse(matrix[i], matrix[j])) {
					tmp++;
				}
			}
			ans = max(tmp, ans);
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix{ {0,0,0},{0,0,1},{1,1,0} };
	cout << s.maxEqualRowsAfterFlips(matrix) << endl;
}


