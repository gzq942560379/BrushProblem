//
// Created by guozhuoqiang on 2019-03-14.
//

#include <iostream>

using namespace std;

const int maxN = 1001;

long long sum[maxN << 2],add[maxN<<2] = {0};
int A[maxN];     //下标从1开始

int n;

void PushUp(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int ll,int rl){
    if(add[rt]>0){
        add[rt<<1] = add[rt<<1|1] = add[rt];   //标记下推
        //保证下层的向上正确
        sum[rt<<1] = add[rt]*ll;
        sum[rt<<1|1] = add[rt]*rl;
        //消除标记
        add[rt] = 0;
    }
}

void Build(int l,int r,int rt){
    if(l == r){
        sum[rt] = A[l];
        return;
    }
    int m = (l+r)>>1;
    Build(l,m,rt<<1);
    Build(m+1,r,rt<<1|1);
    PushUp(rt);
}

long long Query(int L, int R, int l, int r, int rt){
    if(l >= L && r <=  R) return sum[rt];
    int m = (l+r)>>1;
    PushDown(rt,m-l+1,r-m);
    long long ans = 0;
    if(m >= L) ans += Query(L,R,l,m,rt<<1);
    if(m < R) ans += Query(L,R,m+1,r,rt<<1|1);
    return ans;
}

void Update(int I,int C,int l,int r,int rt){
    if(l == r){
        sum[rt] += C;
        return;
    }
    int m = (l+r)>>1;
    if(I <= m) Update(I,C,l,m,rt<<1);
    else       Update(I,C,m+1,r,rt<<1|1);
    PushUp(rt);
}

void UpdateRegion(int L,int R,int C,int l,int r,int rt){
    if(l >= L&&r<=R){
        sum[rt] += C*(r-l+1);
        add[rt] += C;
        return;
    }
    int m = (l+r)>>1;
    PushDown(rt,m-l+1,r-m);
    if(m>=L) UpdateRegion(L,R,C,l,m,rt<<1);
    if(m<R)  UpdateRegion(L,R,C,m+1,r,rt<<1|1);
    PushUp(rt);
}

int main(){
    int n = 10;
    for (int i = 1; i <=  n; ++i) {
        A[i]= i;
    }
    Build(1,n,1);
    long long ans = Query(2, n - 1, 1, n, 1);
    cout << ans <<endl;
    Update(5,5,1,n,1);
    ans = Query(2,n-1,1,n,1);
    cout << ans << endl;
    UpdateRegion(3,6,7,1,n,1);
    ans = Query(2,n-1,1,n,1);
    cout << ans << endl;
    return 0;
}

