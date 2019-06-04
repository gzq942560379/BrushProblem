//
// Created by gzq on 2019/6/4.
//
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <map>

using namespace std;

// 结果超时。。。

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ret = 0;
        vector<vector<int>> rowSum(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            partial_sum(matrix[i].begin(), matrix[i].end(), rowSum[i].begin());
        }
        for (int i = 0; i < c; i++) {
            for (int j = i; j < c; j++) {
                vector<int> partialRowSum(r);
                if (i > 0)
                    for (int k = 0; k < r; k++)
                        partialRowSum[k] = rowSum[k][j] - rowSum[k][i - 1];
                else
                    for (int k = 0; k < r; k++)
                        partialRowSum[k] = rowSum[k][j];

                vector<int> colSum(r);
                partial_sum(partialRowSum.begin(), partialRowSum.end(), colSum.begin());

//                for (int p = 0; p < r; p++) {
//                    for (int q = p; q < r; q++) {
//                        int temp = p > 0 ? colSum[q] - colSum[p - 1] : colSum[q];
//                        if (temp == target) {
//                            ret++;
//                        }
//                    }
//                }
                map<int, int> m;
                m[0] = 1;
                for (auto t:colSum) {
                    int diff = t - target;
                    if (auto it = m.find(diff);it != m.end()) ret += it->second;
                    m[t]++;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix1{{0, 1, 0},
                                {1, 1, 1},
                                {0, 1, 0}};
    int target1 = 0;
    cout << s.numSubmatrixSumTarget(matrix1, target1) << endl;

    vector<vector<int>> matrix2{{1,  -1},
                                {-1, 1}};
    int target2 = 0;
    cout << s.numSubmatrixSumTarget(matrix2, target2) << endl;
}