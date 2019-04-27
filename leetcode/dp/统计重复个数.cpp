//
// Created by guozhuoqiang on 2019-04-27.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		if (n1 == 0) return 0;
		vector<int> indexes(s2.size() + 1, 0);	
		vector<int> counts(s2.size() + 1, 0);
		int index = 0, count = 0;
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < s1.size(); j++) {
				if (s1[j] == s2[index]) {
					index++;
				}
				if (index == s2.size()) {
					count++;
					index = 0;
				}
			}
			indexes[i] = index;
			counts[i] = count;
			for (int k = 0; k < i; k++) {
				if (indexes[k] == index) {
					int prev_count = counts[k];
					int pattern_count = (counts[i] - counts[k]) * ((n1 - 1 - k) / (i - k));
					int ramain_count = counts[k + (n1 - 1 - k) % (i - k)] - counts[k];
					return (prev_count + pattern_count + ramain_count) / n2;
				}
			}
		}
		return counts[n1 - 1] / n2;
	}
};

int main() {
	Solution s;
	//cout << s.getMaxRepetitions("acb",4,"ab",2) << endl;
	cout << s.getMaxRepetitions("aaa", 20, "aaaaa", 1) << endl;
	return 0;
}