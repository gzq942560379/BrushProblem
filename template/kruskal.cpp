//
// Created by guozhuoqiang on 2019-03-15.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

const int maxN = 100000;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
};

int n;
int p[maxN];  //并查集数据结构

int d[maxN];
int pre[maxN];

list<Edge> g[maxN];

void initUF() {
    for (int i = 0; i < n; i++)
        p[i] = i;
}

int find(int ele) {
    while (ele != p[ele]) {
        ele = p[ele] = p[p[ele]];
    }
    return ele;
}

void un(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return;
    p[pb] = pa;
}


void kruskal() {
    priority_queue<Edge> q;
    for (int i = 0; i < n; i++)
        for(Edge e:g[i])
            q.push(e);
    initUF();
    for(int i = 1;i<n;){
        Edge e = q.top();
        q.pop();
        if(find(e.u) == e.v) continue;
        un(e.u,e.v);
        d[e.v] = e.w;
        pre[e.v] = e.u;
        i++;
    }
}

int main(){
    return 0;
}