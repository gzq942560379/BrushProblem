#include<iostream>
#include <algorithm>
#include<queue>

//某个坐标在某个时间段是危险的  3维bfs搜索
using namespace std;

#define rep(i,s,e) for(int i = s;i<e;i++)

const int maxN = 101;
const int maxM = 101;
const int maxT = 301;

bool vis[maxN][maxM][maxT];

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};  //(row,col)

int n,m,t;

struct Node{
    int r,c,t;
};

void bfs(){
    Node start;
    start.r = 1;
    start.c = 1;
    start.t = 0;
    queue<Node> q;
    q.push(start);
    while(!q.empty()){
        Node f = q.front();
        q.pop();
        
        if(f.c == m && f.r == n){
            cout << f.t;
            exit(0);
        }
        rep(i,0,4){
            Node v;
            v.r = f.r+dir[i][0];
            v.c = f.c+dir[i][1];
            v.t = f.t+1;
            if(v.r < 1 || v.r > n || v.c < 1 || v.c > m) continue;
            if(vis[v.r][v.c][v.t]) continue;
            vis[v.r][v.c][v.t] = true;
            q.push(v);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    int r,c,a,b;
    rep(i,0,maxN) rep(j,0,maxM) rep(k,0,maxT) vis[i][j][k] = false;
    
    rep(i,0,t){
        cin >> r >> c >> a >> b;
        b += 1;
        rep(j,a,b){
            vis[r][c][j] = true;
        }
    }
    bfs();
    return 0;
}

