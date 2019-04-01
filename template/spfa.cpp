//
// Created by guozhuoqiang on 2019-03-16.
//
#include <queue>
#include <list>
#include <iostream>

using namespace std;

const int NINF = -100000;
const int INF = 100000;
const int maxN = 100000;


struct Edge{
    int v,w;
    Edge(int v,int w){
        this->v = v;
        this->w = w;
    }
};

int n;
list<Edge> g[maxN];
int d[maxN];
int pre[maxN];
bool inq[maxN];
int update[maxN];

// 求最长路
void spfa_long(int s) {
    queue<int> q;
    fill(d, d + n + 1, NINF);                      //!!!
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
            if (d[v] < d[u] + w) {                //!!!
                d[v] = d[u] + w;
                pre[v] = u;
                update[v] += 1;
                if (update[v] == n) {
                    cout << "正环" << endl;        //!!!
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

// 求最短路
void spfa_short(int s) {
    queue<int> q;
    fill(d, d + n + 1, INF);
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
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v] = u;
                update[v] += 1;
                if (update[v] == n) {
                    cout << "负环" << endl;
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

int main() {
    n = 4;
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
    spfa_short(0);
    cout << d[3] << endl;
    return 0;
}
