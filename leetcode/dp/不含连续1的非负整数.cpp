//
// Created by guozhuoqiang on 2019-04-27.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>
#include<cmath>

using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        int k = log2(num);
        vector<int> f(k + 1);
        f[0] = 1;
        if (k >= 1) f[1] = 2;
        if (k >= 2) f[2] = 3;
        for (int i = 3; i <= k; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        int ans = 0;
        int pattern = 1 << k;
        for (int i = k; i >= 0; i--) {
            if (((num >> i) & 1) == 1) {
                ans += f[i];
                if (i < k && ((num >> (i + 1)) & 1) == 1) {
                    return ans;
                }
            }
        }
        ans += 1;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.findIntegers(5) << endl;
    cout << s.findIntegers(3) << endl;

    return 0;
}