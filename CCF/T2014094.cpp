#include <iostream>
#include <queue>

//多源的bfs求最短路
#define rep(i,s,e) for(int i = s;i<e;i++)

using namespace std;

const int maxN = 1001;
const int maxMKD = maxN*maxN;
const int INF = 1 << 30;

int n,m,k,d;

int map[maxN][maxN];
int cus[maxMKD][3]; //(r,c,d)
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

struct Node{
    int r;
    int c;
    int d;
};

queue<Node> q;

int main(){
    //input
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> d;
    rep(i,0,n+1) rep(j,0,n+1) map[i][j] = INF;
    Node f,node;
    node.d = 0;
    rep(i,0,m){
        cin >> node.r >> node.c;
        q.push(node);
        map[node.r][node.c] = 0;
    }
    rep(i,0,k){
        cin >> cus[i][0] >> cus[i][1] >> cus[i][2];
    }
    rep(i,0,d){
        cin >> node.r >> node.c;
        map[node.r][node.c] = -1;
    }
    //bfs
    
    while(!q.empty()){
        f = q.front();
        q.pop();
        rep(i,0,4){
            node.r = f.r + dir[i][0];
            node.c = f.c + dir[i][1];
            node.d = f.d + 1;
            if(node.r < 1 || node.r > n || node.c < 1 || node.c > n) continue;
            if(map[node.r][node.c] > node.d){
                map[node.r][node.c] = node.d;
                q.push(node);
            }
        }
    }
    long long sum = 0;
    rep(i,0,k){
        sum += map[cus[i][0]][cus[i][1]]*cus[i][2];
    }
    cout << sum;
    
    return 0;
}

