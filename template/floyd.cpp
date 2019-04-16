//
// Created by guozhuoqiang on 2019-03-15.
//
#include <algorithm>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 10000;
const int maxN = 10000;

int n;
int m[maxN][maxN];

void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {                        //无向图优化
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
                m[j][i] = m[i][j];                                 //无向图优化
            }
        }
    }
}

int main() {
    n = 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
            m[i][j] = i == j ? 0 : INF;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][2] = 1;
    m[2][1] = 1;
    floyd();
    cout << m[0][2] << endl;
    return 0;
}