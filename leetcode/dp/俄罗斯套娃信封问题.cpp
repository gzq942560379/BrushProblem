//
// Created by gzq on 4/24/19.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>> &envelopes) {
        if (envelopes.empty())
            return 0;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &x, const pair<int, int> y) {
            return x.first < y.first ? true : x.first > y.first ? false : x.second < y.second;
        });
        int n = envelopes.size();
        vector<int> dp(n);
        dp[0] = 1;
        int ret = 1;
        for (int i = 1; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < i; j++) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    mx = max(mx, dp[j]);
                }
            }
            dp[i] = mx + 1;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> input{
            make_pair(5, 4),
            make_pair(6, 4),
            make_pair(6, 7),
            make_pair(2, 3)
    };
    cout << s.maxEnvelopes(input) << endl;
    return 0;
}
