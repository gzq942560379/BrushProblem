//
// Created by gzq on 4/2/19.
//

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> selectKNumber(vector<int> nums, int k) {
        vector<int> res;
        if (!k) {
            res = nums;
            return res;
        }
        int m = nums.size() - k;
        int n = m;
        for (auto num : nums) {
            while (!res.empty() && n > 0 && res.back() < num) {
                n--;
                res.pop_back();
            }
            res.push_back(num);
        }
        while (!res[0]) res.erase(res.begin());
        while (res.size() != (nums.size() - m)) res.erase(res.end() - 1);
        return res;
    }

    bool isGreater(vector<int> nums1, int i, vector<int> nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> res(k);
        int i = 0, j = 0;
        for (int r = 0; r < k; r++) {
            if (isGreater(nums1, i, nums2, j)) res[r] = nums1[i++];
            else res[r] = nums2[j++];
        }
        return res;
    }

    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> res(k, 0);
        int m = nums1.size();
        int n = nums2.size();
        for (int i = max(0, k - n); i <= m && i <= k; i++) {
            auto v1 = selectKNumber(nums1, i);
            auto v2 = selectKNumber(nums2, k - i);
            vector<int> tmp = merge(v1, v2, k);
            if (isGreater(tmp, 0, res, 0)) res = tmp;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v1{3, 4, 6, 5}, v2{9, 1, 2, 5, 8, 3};
    int k = 5;
    vector<int> result = s.maxNumber(v1, v2, k);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    return 0;
}