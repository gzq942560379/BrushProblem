//
// Created by guozhuoqiang on 2019-03-15.
//

#include <iostream>
#include <list>
#include <algorithm>
#define rep(i,s,e) for(int i = s;i<e;i++)

using namespace std;

const int maxN = 1001;
const int maxM = 100001;
const int INF = 10001;

struct Edge{
    int t;      //指向点
    int w;      //权值
    Edge(int t,int w){
        this->t = t;
        this->w = w;
    }
};

//节点数与边数
int n,m;
//邻接链表实现图   从0号下标开始
list<Edge> g[maxN];

int d[maxN];
bool vis[maxN];
int sum = 0;

void prim(int s){
    //init
    fill(vis,vis+n,false);
    fill(d,d+n,INF);
    d[s] = 0;
    int m,u;
    rep(i,0,n){
        //寻找下一个距离最短的点加入集合中
        m = INF;
        rep(j,0,n){
            if(!vis[j] && m > d[j]){
                m = d[j];
                u = j;
            }
        }
        vis[u] = true;
        sum += d[u];
        //根据该点松弛其他点距离
        for(list<Edge>::iterator it = g[u].begin();it != g[u].end();it++){
            if(d[it->t] > it->w ){
                d[it->t] = it->w;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int u,v,w;
    rep(i,0,m){
        cin >> u >> v>> w;
        u -= 1;
        v -= 1;
        g[u].push_back(Edge(v,w));
        g[v].push_back(Edge(u,w));
    }
    prim(0);
    cout << sum;
    return 0;
}