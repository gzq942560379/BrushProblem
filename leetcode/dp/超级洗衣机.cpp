//
// Created by guozhuoqiang on 2019-04-27.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// TODO û����������

class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		int total = accumulate(machines.begin(),machines.end(),0);
		int n = machines.size();
		if (total % n != 0) return -1;
		int average = total / n;
		int mx = 0,bias = 0;
		for (auto num : machines) {
			bias += num - aver;
			mx = max(mx, max(num - aver, abs(bias)));
		}
		return cnt;
	}
};

int main() {
	Solution s;
	vector<int> input1{ 1,0,5 };
	cout << s.findMinMoves(input1) <<endl;
	vector<int> input2{ 0,3,0 };
	cout << s.findMinMoves(input2) << endl;
	return 0;
}