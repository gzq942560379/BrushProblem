//
// Created by guozhuoqiang on 2019-03-22.
//
#include <iostream>
#include <algorithm>
#include <algorithm>
using namespace std;

const int maxN = 101;

struct Node {
    int x, y;

    bool operator <(const Node &n) const {
        return this->y < n.y;
    }
};

int n;
Node nodes[maxN];

int main() {
    ios::sync_with_stdio(false);
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> nodes[i].x >> nodes[i].y;
        }
        sort(nodes, nodes + n);
        int cnt = 1;
        int end = nodes[0].y;
        for(int i = 1;i<n;i++){
            if(nodes[i].x >= end){
                end = nodes[i].y;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


