//
// Created by guozhuoqiang on 2019-03-28.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    int longestValidParentheses2(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        int mx = 0;
        for (int i = 2; i <= n; i++) {
            char x = s[i - 1];
            if (x == '(') dp[i] = 0;
            else {
                if (s[i - 2] == '(')
                    dp[i] = dp[i - 2] + 2;
                else if (s[i - dp[i - 1] - 2] == '(')
                    dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};


int main() {
    Solution s;
    cout << s.longestValidParentheses2("(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(");

    return 0;
}
