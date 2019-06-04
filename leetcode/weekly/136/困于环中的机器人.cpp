//
// Created by gzq on 5/13/19.
//
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[]{0, 1, 0, -1};
        int dy[]{-1, 0, 1, 0};
        int x = 0, y = 0, z = 0;
        instructions = instructions + instructions;
        instructions = instructions + instructions;
        for (char ch:instructions) {
            if (ch == 'G') {
                x += dx[z];
                y += dy[z];
            } else if (ch == 'L') {
                z = z + 3 & 3;
            } else if (ch == 'R') {
                z = z + 1 & 3;
            }
        }
        return x == 0 && y == 0;
    }
};


int main() {
    Solution s;
    cout << s.isRobotBounded("GGLLGG") << endl;
    cout << s.isRobotBounded("GG") << endl;
    cout << s.isRobotBounded("GL") << endl;
    return 0;
}