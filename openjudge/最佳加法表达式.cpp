//
// Created by guozhuoqiang on 2019-03-22.
//

/*
 * 循环 递增还是递减一定要注意 这个地方debug花了一个小时
 *
 * dp[i][j] = min(dp[i-1][k]+num(k+1,j)  k取(i，j-1))  一维空间  反序迭代
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[51][60];
int ll[51];
int temp[60];
int tl;

int temp2[60];
int tl2;

inline int char2int(char ch) {
    return ch - '0';
}

void num(string &s, int f, int t, int (&ret)[60], int &ll) {
    ll = 0;
    for (int i = t; i >= f; i--) {
        ret[ll++] = char2int(s[i]);
    }
}

void add(int (&a)[60], int (&b)[60], int (&ret)[60], int la, int lb, int &lr) {
    lr = 0;
    int mi = min(la, lb);
    int c = 0;
    for (lr = 0; lr < mi; lr++) {
        c += a[lr] + b[lr];
        ret[lr] = c % 10;
        c /= 10;
    }
    if(la > lb){
        for (; lr < la; lr++) {
            c += a[lr];
            ret[lr] = c % 10;
            c /= 10;
        }
    }else{
        for (; lr < lb; lr++) {
            c += b[lr];
            ret[lr] = c % 10;
            c /= 10;
        }
    }
    while(c != 0){
        ret[lr++] = c % 10;
        c /= 10;
    }
}

bool mygreater(int (&a)[60], int (&b)[60],int la,int lb){
    if(la > lb) return true;
    if(la < lb) return false;
    for(int i = la-1 ;i>=0;i--){
        if(a[i]> b[i]) return true;
        if(a[i]< b[i]) return false;
    }
    return false;
}

int main() {
    int m;
    string s;
    while (cin >> m >> s) {
        //init m = 0
        int n = s.size();
        ll[0] = 0;
        for (int i = 1; i <= n; i++) {
            ll[i] = i;
            num(s, 0, i - 1, dp[i], ll[i]);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j > i; --j) {
                num(s,i,j-1,temp,tl);
                add(dp[i],temp,dp[j],ll[i],tl,ll[j]);
                for (int k = i + 1; k < n; ++k) {
                    num(s,k,j-1,temp,tl);
                    add(dp[k],temp,temp2,ll[k],tl,tl2);
                    if(mygreater(dp[j],temp2,ll[j],tl2)){
                        ll[j] = tl2;
                        for(int q = 0;q<tl2;q++){
                            dp[j][q]=temp2[q];
                        }
                    }
                }
            }
        }
        for(int i = ll[n]-1;i>=0;i--){
            cout << dp[n][i];
        }
        cout << endl;
    }
    return 0;
}
