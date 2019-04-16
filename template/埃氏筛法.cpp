//
// Created by guozhuoqiang on 2019-03-15.
//
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 100000;  // > sqrt(MAX_INT)

int primeNum = 0;
bool isPrime[maxN + 1];  //i是否为素数
int prime[maxN + 1];     //第i个素数

void init() {
    fill(isPrime, isPrime + maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    int i = 2;
    for (; i*i <= maxN; i++) {
        if (isPrime[i]) {
            prime[++primeNum] = i;
            for (int j = i * i; j <= maxN; j += i) isPrime[j] = false;
        }
    }
    for(;i<=maxN;i++){
        if (isPrime[i]) {
            prime[++primeNum] = i;
        }
    }
}

int main(){
    init();
    for(int i = 0;i<primeNum;i++){
        cout << prime[i] << endl;
    }
    return 0;
}

