//
// Created by guozhuoqiang on 2019-03-15.
//
#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#define rep(i,s,e) for(int i = s;i < e;i++)
using namespace std;

const int maxN = 10001;
const int maxM = 100001;

int n;
int m;

set<int> g[maxN];   //利用set自动排序功能  自动按字典序访问
bool vis[maxN][maxN];  //每条边只能访问一次

stack<int> path;  //记录遍历路径

int p[maxN];  //并查集数据结构

void initUF(){
    rep(i,0,n) p[i] = i;
}

int find(int ele){
    while(ele != p[ele]){
        ele = p[ele] = p[p[ele]];
    }
    return ele;
}

void un(int a,int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;
    p[pb] = pa;
}

void dfs(int u){
    for(set<int>::iterator it = g[u].begin(); it != g[u].end();it++){
        if(!vis[u][*it]) {
            vis[u][*it] = true;
            vis[*it][u] = true;
            dfs(*it);
        }
    }
    path.push(u);
}

int main(){
    ios::sync_with_stdio(false);
    //input
    cin >> n >> m;
    initUF();
    int f,t;
    rep(i,0,m){
        cin >> f >> t;
        f -= 1;
        t -= 1;
        g[f].insert(t);
        g[t].insert(f);
        un(f,t);
    }
    //判断连通性
    rep(i,1,n) {
        if (find(i - 1) != find(i)) {
            cout << -1;
            exit(0);
        }
    }

    //判断是否具有欧拉回路
    //无向图 出入度均为偶数 或 有两个奇数 必须从奇数节点出发
    int counter = 0;
    rep(i,0,n){
        if(g[i].size() & 1){  //奇数
            counter++;
        }
    }
    if(!(counter==0 || (counter==2&&g[0].size() & 1))) {
        cout << -1;
        exit(0);
    }

    //得到欧拉回路
    dfs(0);

    //输出路径
    while(!path.empty()){
        cout << path.top()+1 << " ";
        path.pop();
    }
    return 0;
}




