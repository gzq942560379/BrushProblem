//
// Created by gzq on 2019/4/28.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:

	/*
	如果我们确定了中间子数组的位置，则左右两端的子数组就确定了
	*/
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> w(nums.size() - k + 1, 0);
		for (int i = 0; i < k; i++) { w[0] += nums[i]; }
		for (int i = 1; i < w.size(); i++) {
			w[i] = w[i - 1] + nums[k + i - 1] - nums[i - 1];
		}
		int n = w.size();
		vector<int> left(n);      // 左边i个中最大下标
		int best = 0;
		for (int i = 0; i < n; i++) {
			if (w[i] > w[best]) best = i;
			left[i] = best;
		}
		vector<int> right(n);     // 右边i个中最大下标
		best = n - 1;
		for (int i = n-1; i >= 0; i--) {
			if (w[i] >= w[best]) best = i;
			right[i] = best;
		}
		vector<int> ans{0,0,0};
		int now = 0;
		for (int mid = k; mid + k < n; mid++) {
			int i = left[mid - k], j = right[mid + k];
			int val = w[i] + w[mid] + w[j];
			if (val > now) {
				now = val;
				ans[0] = i;
				ans[1] = mid;
				ans[2] = j;
			}
		}
		return ans;
	}

};

int main() {
	Solution s;
	vector<int> input1{1,2,1,2,6,7,5,1};
	vector<int> output1 = s.maxSumOfThreeSubarrays(input1, 2);
	copy(output1.begin(), output1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}