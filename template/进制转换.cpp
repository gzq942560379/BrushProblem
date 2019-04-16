//
// Created by guozhuoqiang on 2019-03-10.
//
/*
 *实现大正整数n进制转为m进制
 */
#include <cstring>
#include <iostream>
#include <algorithm>
int m;  // origin
int n;  // to


using namespace std;

const int maxL = 1001;

char a[maxL];        //高位在前    原始数据 与 商
char b[maxL];           //高位在前    结果

int la;
int lb;

int char2int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    printf("error\n");
    return -1;
}

char int2char(int i) {
    if (i >= 0 && i <= 9) {
        return i + '0';
    } else if (i >= 10 && i <= 35) {
        return i + 'A' - 10;
    }
    printf("error\n");
    return -1;
}

bool isZero(char* s,int l){
    int i = 0;
    for (; i < l && s[i] == '0'; ++i);
    return  i == l;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> m >> n) {
        cin >> a;
        la = strlen(a);
        lb = 0;
        while (!isZero(a,la)){
            int r = 0, q;
            for (int i = 0; i < la; ++i) {
                r = char2int(a[i]) + r * m;
                a[i] = int2char(r/n);
                r %= n;
            }
            b[lb++] = int2char(r);
        }
        if(lb == 0){
            cout << 0;
        }else{
            lb--;
            while (lb>=0){
                cout << b[lb];
                lb--;
            }
        }
        cout << endl;
    }
    return 0;
}





