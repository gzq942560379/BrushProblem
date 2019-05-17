//
// Created by gzq on 5/13/19.
//

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

// 图着色问题

using namespace std;

class Solution {
public:

    static void color(const int N, const vector<vector<int>> &paths, int index, vector<int> &colors) {



    }

    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
        vector<vector<int>> g(N, vector<int>());  // 邻接表
        for (const vector<int> &pair:paths) {
            g[pair[0] - 1].push_back(pair[1]);
        }
        vector<int> colors(N, -1);
        color(N, g, 0, colors);

    }
};


int main() {
    Solution s;
    vector<vector<int>> paths1{{1, 2},
                               {2, 3},
                               {3, 1}};
    s.gardenNoAdj(3, paths1);

    return 0;
}