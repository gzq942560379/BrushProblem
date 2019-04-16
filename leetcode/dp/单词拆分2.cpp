//
// Created by guozhuoqiang on 2019-03-24.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void dfs(int u, string suffix, const vector<vector<int>> &pre, const string &s, vector<string> &ret) {
        if (pre[u].empty()) {
            if (!suffix.empty())
                ret.push_back(suffix);
            return;
        }
        for (int i:pre[u]) {
            string ss = s.substr(u - i, i);
            if (!suffix.empty()) {
                ss += " ";
                ss += suffix;
            }
            dfs(u - i, ss, pre, s, ret);
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> result;
        if (s.empty()) return result;
        if (wordDict.empty()) return result;
        const char *ss = s.c_str();
        int n = s.size();
        vector<bool> dp(n + 1, false);
        vector<vector<int>> pre(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (const string &ds:wordDict) {
                int k = ds.size();
                if (i - k >= 0 && dp[i - k] && equal(ss + i - k, ss + i, ds.c_str())) {
                    dp[i] = true;
                    pre[i].push_back(k);
                }
            }
        }
        dfs(n, "", pre, s, result);
        return result;
    }
};


int main() {
    Solution s;
    string ss{"pineapplepenapple"};
    vector<string> v{"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> &&result = s.wordBreak(ss, v);
    copy(result.begin(), result.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}