//
// Created by gzq on 4/27/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


// find 方案 比异常快很多
template<typename K, typename V>
V getDefault(const unordered_map<K, V> &map, const K &key, const V &d) {
    auto it = map.find(key);
    if (it != map.end()) {
        return it->second;
    }
    return d;
}

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        vector<unordered_map<long long, int>> dp(n, unordered_map<long long, int>());
        int sum = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = static_cast<long long>(A[i]) - A[j];
                int count = getDefault(dp[j], diff, 0);
                dp[i][diff] = getDefault(dp[i], diff, 0) + count + 1;
                sum += count;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> input1{2, 4, 6, 8, 10};
    cout << s.numberOfArithmeticSlices(input1) << endl;
    vector<int> input2{0, 2000000000, -294967296};
    cout << s.numberOfArithmeticSlices(input2) << endl;
    vector<int> input3{2, 2, 3, 4};
    cout << s.numberOfArithmeticSlices(input3) << endl;
    return 0;
}