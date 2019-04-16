//
// Created by guozhuoqiang on 2019-03-10.
//
/*
 *
 * opt算法实现  未来最迟访问
 *
 * 95 运行时间过长
 * 经过测试  主要问题在与算法逻辑有问题  忽略了代理ip只有一种造成的死循环 和cin 还是 stdio  char* 还是 unsigned int 无关
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const unsigned int maxIP = 0xffffffff;

const int maxN = 1000;
const int maxM = 5000;

int n, m;
/*
 * opt 最佳替换算法实现
 */

unsigned int proxy[maxN];
unsigned int server[maxM];

int f(unsigned int *remainServer, int remainLen) {
    int m = -1;
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (; j < remainLen; ++j) {
            if (proxy[i] == remainServer[j]) {
                m = j > m ? j : m;
                break;
            }
        }
        if (j == remainLen) return 0;
    }
    if (n == 1 && m != -1)
        return -1;
    return 1 + f(remainServer + m, remainLen - m);
}

int ip[4];

unsigned int ip2uint(int ip[4]) {
    unsigned int r;
    for (int i = 0; i < 4; i++) {
        r = (r << 8) + ip[i];
    }
    return r;
}

int main() {
    scanf("%d", &n);
    unsigned int t = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
        proxy[i] = ip2uint(ip);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
        server[i] = ip2uint(ip);
    }
    printf("%d", f(server, m));
    return 0;
}