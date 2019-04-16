#include <iostream>
#include <algorithm>
#include <list>

// prim 求最小生成树权值和
#define rep(i,s,e) for(int i = s;i<e;i++)

using namespace std;

const int maxN = 1001;
const int maxM = 100001;
const int INF = 10001;

struct Edge{
    int t;
    int w;
    Edge(int t,int w){
        this->t = t;
        this->w = w;
    }
};

int n,m;
list<Edge> g[maxN];

int d[maxN];
bool vis[maxN];
int sum = 0;

void prim(int s){
    fill(vis,vis+n,false);
    fill(d,d+n,INF);
    d[s] = 0;
    
    int m,u;
    rep(i,0,n){
        m = INF;
        rep(j,0,n){
            if(!vis[j] && m > d[j]){
                m = d[j];
                u = j;
            }
        }
        vis[u] = true;
        sum += d[u];
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