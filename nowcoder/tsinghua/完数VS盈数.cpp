//
// Created by guozhuoqiang on 2019-03-11.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 60;

int table[maxN + 1];  //因数个数

void init() {
    fill(table, table + maxN + 1, 1);
    table[1] = 1;
    for (int i = 2; i * i <= maxN; i++) {
        table[i * i] += i;
        for (int j = i + 1; i * j <= maxN; j += 1) {
            table[i*j] += i+j;
        }
    }
}

int E[maxN];
int G[maxN];
int le = 0;
int lg = 0;

int main() {
    ios::sync_with_stdio(false);
    init();
    for (int i = 2; i <= 60; i++) {
        if (table[i] == i){
            E[le++] = i;
        }else if(table[i] > i){
            G[lg++] = i;
        }
    }
    cout << "E:";
    for(int i = 0;i<le;i++){
        cout << " "<<E[i];
    }
    cout << endl;
    cout << "G:";
    for(int i = 0;i<lg;i++){
        cout << " "<<G[i];
    }
    cout << endl;
    return 0;
}