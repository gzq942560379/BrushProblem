//
// Created by guozhuoqiang on 2019-03-16.
//

// 差分约束 求解再卖菜
// spfa 求最长路 有正环时无解  允许有负环
// 差分约束转化的图可能不连通 需要添加虚拟节点 从源到所有节点有一条权为0的有向边

#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

const int NINF = -1 << 30;
const int maxN = 301;
int n;
int a[maxN], s[maxN];     //前缀和

struct Edge {
    int v, w;

    Edge(int v, int w) : v(v), w(w) {}
};

list<Edge> g[maxN];
int d[maxN];
bool inq[maxN];
int pre[maxN];
int update[maxN];

// 求最长路
void spfa(int s) {
    queue<int> q;
    fill(d, d + n + 1, NINF);
    fill(inq, inq + n + 1, false);
    fill(update, update + n + 1, false);
    d[s] = 0;
    pre[s] = -1;
    q.push(s);
    inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (Edge e:g[u]) {
            int v = e.v, w = e.w;
            if (d[v] < d[u] + w) {
                d[v] = d[u] + w;
                pre[v] = u;
                update[v] += 1;
                if (update[v] == n) {
                    cout << "正环" << endl;
                    exit(0);
                }
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}


inline void addEdge(int u, int v, int w) {
    g[u].push_back(Edge(v, w));
}

int main() {
    cin >> n;
    a[0] = s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    for (int i = 1; i <= n; ++i) addEdge(i - 1, i, 1);
    addEdge(0, 2, 2 * a[1]), addEdge(2, 0, -2 * a[1] - 1);
    addEdge(n - 2, n, 2 * a[n]), addEdge(n, n - 2, -2 * a[n] - 1);
    for (int i = 2; i < n; i++) {
        addEdge(i - 2, i + 1, 3 * a[i]);
        addEdge(i + 1, i - 2, -3 * a[i] - 2);
    }
    //添加虚拟节点
    for (int i = 1; i <= n; i++) {
        addEdge(0, i, 0);
    }
    spfa(0);

    for (int i = 1; i <= n; ++i) {
        a[i] = d[i] - d[i - 1];
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}