//
// Created by guozhuoqiang on 2019-03-15.
//
#include <iostream>
#include <list>
#include <algorithm>
#define rep(i,s,e) for(int i = s;i<e;i++)

using namespace std;

const int maxN = 10001;
const int maxM = 100001;

int n,m; // 节点数 边数
list<int> g[maxN],gg[maxN];  //原图 与 逆图

int c = 0;          // 强连通分支数
int t = 0;          // 时间戳
bool vis[maxN];

int ed[maxN];      //按结束访问时间排序 第i个对应的节点
int label[maxN];   //i号节点所属的连通分支
int cnt[maxN] = {0}; //第i号连通分支中的节点个数

void positiveDFS(int u){
    vis[u] = true;
    for(auto it = g[u].begin();it!= g[u].end();it++){
        if(!vis[*it])
            positiveDFS(*it);
    }
    ed[n-(++t)] = u;
}

void negativeDFS(int u){
    vis[u] = false;
    label[u] = c;
    ++cnt[c];
    for(auto it = gg[u].begin();it!= gg[u].end();it++){
        if(vis[*it])
            negativeDFS(*it);
    }
}

void SCC(){
    rep(i,0,n)
        if(!vis[i])
            positiveDFS(i);

    rep(i,0,n) {
        if(vis[ed[i]]){
            negativeDFS(ed[i]);
            c++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int f,t;
    rep(i,0,m){
        cin >> f >> t;
        f -= 1;
        t -= 1;
        g[f].push_back(t);
        gg[t].push_back(f);
    }
    SCC();
    return 0;
}

