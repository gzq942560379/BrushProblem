//
// Created by gzq on 6/4/19.
//
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	bool match(string p,string s) {
		int T = p.size() / s.size();
		int n = s.size();
		for (int t = 0; t < T; ++t) {
			for (int i = 0; i < n; ++i) {
				if (p[i + t * n] != s[i]) {
					return false;
				}
			}
		}
		return true;
	}
	string gcdOfStrings(string str1, string str2) {
		int l = gcd(str1.size(), str2.size());
		string str = str1.substr(0, l);
		if (match(str1, str) && match(str2, str)) {
			return str;
		}
		return "";
	}
};

int main() {
	Solution s;
	cout << s.gcdOfStrings("ABABAB", "ABAB") << endl;
	return 0;
}