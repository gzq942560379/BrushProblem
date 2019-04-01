//
// Created by guozhuoqiang on 2019-03-10.
//
#include <iostream>

using namespace std;

const int q = 1000000000;
const int maxN = 1000000;

int f[maxN+1];

void init(){
    f[1] = 1;
    f[2] = 2;
    for(int i = 3;i<=maxN;i++){
        if((i&1) > 0 ){
            f[i] = f[i-1];
        }else {
            f[i] = (f[i-1]+f[i/2])%1000000000;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int t;
    while (cin >> t){
        cout << f[t] << endl;
    }
    return 0;
}