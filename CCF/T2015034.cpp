#include <iostream>
#include <list>
#include <queue>

//双bfs
//求树的直径

#define rep(i,s,e) for(int i = s;i<e;i++)

using namespace std;

const int maxMN = 20001;


list<int> g[maxMN];

int n,m;

int d[maxMN];
bool vis[maxMN];

int maxD = 0;
int idx = -1;

void bfs(int s){
    fill(vis,vis+m+n,false);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = true;
    maxD = d[s];
    idx = s;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(list<int>::iterator it = g[u].begin();it!=g[u].end();it++){
            if(!vis[*it]){
                d[*it] = d[u]+1;
                vis[*it] = true;
                q.push(*it);
                maxD = d[*it];
                idx = *it;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    //input build tree
    cin >> n >> m;
    int p;
    rep(i,1,n){
        cin >> p;
        p -= 1;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    rep(j,0,m){
        cin >> p;
        p -= 1;
        g[j+n].push_back(p);
        g[p].push_back(j+n);
    }
    bfs(0);
    bfs(idx);
    cout << maxD;
    return 0;
}

