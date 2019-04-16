#include<iostream>
#include<list>
#include <algorithm>
#define rep(i, s, e) for(int i = (s);i<(e);i++)

//dijkstra dfs 得到所有最短路 dfs 遍历所有最短路 统计第二指标得到最优解

using namespace std;

const int INF = 1 << 30;
const int maxN = 10001;
const int maxM = 100001;
const int maxW = 1001;

struct Edge {
    int t;
    int w;

    Edge(int t, int w) {
        this->t = t;
        this->w = w;
    }
};

int n;
int m;
list<Edge> g[maxN];

int d[maxN];
bool vis[maxN];
list<int> pre[maxN];
list<int> path;

void dijkstra(int source) {
    fill(d, d + n, INF);
    fill(vis, vis + n, false);
    d[source] = 0;
    rep(i, 0, n) {
        int u;
        int m = INF;
        rep(j, 0, n) {
            if (!vis[j] && m > d[j]) {
                m = d[j];
                u = j;
            }
        }
        vis[u] = true;
        for (auto it = g[u].begin(); it != g[u].end(); it++) {
            int v = it->t;
            int w = it->w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v].clear();
                pre[v].push_back(u);
            } else if (d[v] == d[u] + w) {
                pre[v].push_back(u);
            }
        }
    }
}

void dfs(int u) {
    path.push_front(u);
    if (pre[u].empty()) {
        for (int i:path) {
            cout << i << " ";
        }
        cout << endl;
        path.pop_front();
        return;
    }
    for (int i:pre[u])
        dfs(i);
    path.pop_front();
}

int main() {
    ios::sync_with_stdio(false);
    n = 4, m = 5;
    g[0].push_back(Edge(1, 4));
    g[1].push_back(Edge(0, 4));
    g[0].push_back(Edge(2, 5));
    g[2].push_back(Edge(0, 5));
    g[1].push_back(Edge(2, 2));
    g[2].push_back(Edge(1, 2));
    g[1].push_back(Edge(3, 3));
    g[3].push_back(Edge(2, 3));
    g[2].push_back(Edge(3, 2));
    g[3].push_back(Edge(2, 2));
    dijkstra(0);
    cout << d[3] << endl;
    dfs(n - 1);
    return 0;
}

