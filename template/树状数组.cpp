//
// Created by guozhuoqiang on 2019-03-15.
//

#include <iostream>
#include <algorithm>
#define rep(i,s,e) for(int i = s;i<e;i++)
#define lowbit(i) -(i)&(i)

using namespace std;

const int maxN = 100001;

int n;
long long tree[maxN];
int a[maxN];                 //下标从1开始

void Update(int i,int val){
    while(i<=n){
        tree[i] += val;
        i += lowbit(i);
    }
}

long long Query(int i){
    long long sum = 0;
    while(i>0){
        sum += tree[i];
        i -= lowbit(i);
    }
    return sum;
}

void Build(){
    fill(tree,tree+n+1,0);
    for(int i = 1;i<=n;i++){
        Update(i,a[i]);
    }
}

int main(){
    long long ans;
    //单点更新 区间查询
    //input
    n = 5;
    for(int i = 1;i<=n;++i){
        a[i] = i;
    }
    Build();
    Update(3,1);                 // (3) +1
    ans = Query(5)-Query(0);     // sum(1,5)  assert ans == 16
    cout << ans << endl;

    //区间更新 单点查询
    n = 5;
    for(int i = 1;i<=n;++i){
        a[i] = i;
    }
    //差分
    for(int i = n-1;i;--i){
        a[i+1] -= a[i];
    }
    Build();
    Update(2,1),Update(5,-1);  //(2,4) + 1;
    ans = Query(3);            //assert ans == 4
    cout << ans << endl;
    return 0;
}
