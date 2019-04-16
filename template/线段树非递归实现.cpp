//
// Created by guozhuoqiang on 2019-03-14.
//

/*
 * 线段树非递归实现 标记持久化
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1001;

//下标从1开始
long long sum[maxN << 2] = {0}, add[maxN << 2] = {0};

int N;
int M;

inline void up(int x) {
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
}

void Build() {
    for (int i = M - 1; i; i--)
        up(i);
}

//点修改
void Update(int p, int v) {
    for (int s = p + M; s; s >>= 1)
        sum[s] += v;
}

//点修改下的区间查询
long long Query(int l, int r) {
    long long ans = 0;
    for (int s = l + M - 1, t = r + M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) ans += sum[s ^ 1];
        if (t & 1) ans += sum[t ^ 1];
    }
    return ans;
}

//标记持久化
//区间修改
void UpdateRegion(int l, int r, int v) {
    int s = l + M - 1, t = r + M + 1;
    int ln = 0, rn = 0, x = 1;
    for (; s ^ t ^ 1; s >>= 1, t >>= 1, x <<= 1) {
        sum[s] += v * ln;
        sum[t] += v * rn;
        if (~s & 1) add[s ^ 1] += v, ln += x;;
        if (t & 1) add[t ^ 1] += v, rn += x;
    }
    sum[s] += v * ln;
    sum[t] += v * rn;
    s >>= 1,ln += rn;
    for (; s ^ 1; s >>= 1) sum[s] += v * ln;
}

//区间查询
long long QueryRegion(int l, int r) {
    int s = l + M - 1, t = r + M + 1;
    int ln = 0, rn = 0, x = 1;
    int ans = 0;
    for(;s^t^1;s>>=1,t>>=1,x<<=1){
        if(add[s]) ans += ln*add[s];
        if(add[t]) ans += rn*add[t];

        if(~s&1)ans += sum[s^1]+x*add[s^1],ln+=x;
        if(t&1)ans += sum[t^1]+x*add[t^1],rn+=x;
    }
    if(add[s]) ans += ln*add[s];
    if(add[t]) ans += rn*add[t];
    s>>=1,ln+=rn;
    for(;s^1;s>>=1) ans += add[s]*ln;
    return ans;
}


int main() {
    N = 7;
    for (M = 1; M <= N + 1; M <<= 1);
    for (int i = 1; i <= N; i++) {
        sum[i + M] = i;
    }
    Build();
    long long ans;
    Update(5, 5);
    ans = Query(2, N - 1);
    cout << ans << endl;
    UpdateRegion(3,5,1);
    ans = QueryRegion(1,7);
    cout << ans << endl;
    return 0;
}
