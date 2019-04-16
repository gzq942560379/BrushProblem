//
// Created by guozhuoqiang on 2019-03-12.
//
#include <iostream>
#include <cstring>
#include <algorithm>
//大整数与整数乘除加法

using namespace std;

const int maxL = 1001;

char str[1001];
int s[1001];//origin   做除法 高位在前
int t[1001];//ans      做乘法 低位在前
int sl, tl;

void badd(int r) {
    for(int i = 0;i<tl&&r>0;i++){
        r += t[i];
        t[i] = r%10;
        r /= 10;
    }
    if(r != 0){
        t[tl++] = r % 10;
    }
}

void bmul() {
    int c = 0;
    for (int i = 0; i < tl; i++) {
        c += t[i] << 1;
        t[i] = c % 10;
        c /= 10;
    }
    while (c != 0) {
        t[tl++] = c % 10;
        c /= 10;
    }
}

int bdiv() {
    int r = 0;
    for (int i = 0; i < sl; i++) {
        r = r * 10 + s[i];
        s[i] = r >> 1;
        r &= 1;
    }
    return r;
}

bool isZero(int *s, int len) {
    for (int i = 0; i < len; i++) {
        if (s[i] != 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> str;
    sl = 0;
    tl = 0;
    while (str[sl] != '\0') {
        s[sl] = str[sl] - '0';
        sl += 1;
    }
    int r;
    while (!isZero(s, sl)) {
        r = bdiv();    //s大数除2 返回余数 原地保留商
        bmul();        //t大数乘2
        badd(r);       //t大数加法
    }
    for(int i = tl-1;i>=0;i--){
        cout << t[i];
    }
    cout << endl;
    return 0;
}