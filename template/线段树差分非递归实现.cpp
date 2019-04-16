//
// Created by guozhuoqiang on 2019-03-15.
//
/*
 * 先将数列差分，每个数减去前一个数。然后，原本的数就变成了新数列的前缀和。
 * 原本的前缀和就变成了新数列的前缀和的前缀和。
 * A[i] input
 * a[i] = A[i] - A[i-1]  差分  化绝对为相对
 * S[i] = sum_1^i(a[i])   差分的前缀和 等于 原数组
 * P[i] = sum_1^i(i*a[i])  用于计算SS[i]
 * SS[i} = sum_1^i(S[i])   原数组的前缀和  差分的前缀和的前缀和
 *       = sum_1^i((n+1-i)*a[i])
 *       = sum_1^i((n+1)*a[i] - i*a[i])
 *       = sum_1^i((n+1)*a[i]) - sum_1^i(i*a[i])
 *       = (n+1)S[i] - P[i]
 * Update(l,r,v)    a[l]+v,a[r+1]-v 区间修改转化为点修改
 * Query(l,r) = SS[r] - SS[l-1];
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1001;
//下标从1开始

int N, M;
long long S[maxN << 2], P[maxN << 2];

inline void up(int p) {
    S[p] = S[p << 1] + S[p << 1 | 1];
    P[p] = P[p << 1] + P[p << 1 | 1];
}

void build() {
    S[0] = P[0] = 0;
    for (int i = N + 1; i < M; i++) S[i] = 0;
    for (int i = M - 1; i; --i) S[M + i] -= S[M + i - 1];         //
    for (int i = 1; i < M; ++i) P[M + i] = S[M + i] * i;
    for (int i = M - 1; i; --i) up(i);
}

void Update(int l, int r, int v) {
    int s = l + M, t = r + M + 1;
    S[s] += v;
    S[t] -= v;
    P[s] += l * v;
    P[t] -= v * (r + 1);
    while (s ^ 1) s >>= 1, up(s);
    while (t ^ 1) t >>= 1, up(t);
}

long long SS(int r) {
    long long sumS = 0, sumP = 0;
    for (int t = r + M + 1; t ^ 1; t >>= 1)
        if (t & 1) sumS += S[t ^ 1], sumP += P[t ^ 1];
    return (r + 1) * sumS - sumP;
}

long long Query(int l,int r){
    return SS(r) - SS(l-1);
}

int main() {
    //input
    int N = 7;
    for (M = 1; M <= N + 1; M <<= 1);
    for (int i = 1; i <= N; i++) S[i + M] = i;
    //build
    build();
    long ans;
    Update(2,4,1);
    ans  = Query(1,7);
    cout << ans << endl;
    return 0;
}



