//
// Created by guozhuoqiang on 2019-03-10.
//
#include <iostream>
#include <algorithm>
using namespace std;

//const int maxN = 100001;  //sqrt(maxN)  = 31622
const int maxN = 100001;

int primeNum = 0;
bool isPrime[maxN+1];  //i是否为素数
int prime[maxN+1];     //第i个素数

void init() {
    fill(isPrime, isPrime + maxN+1, true);
    isPrime[0] = isPrime[1] = false;
    int i;
    for (i = 2; i*i <= maxN; i++) {
        if (isPrime[i]) {
            prime[++primeNum] = i;
            for (int j = i * i; j <= maxN; j += i) isPrime[j] = false;
        }
    }
    for(;i<=maxN;i++){
        if(isPrime[i]) {
            prime[++primeNum] = i;
        }
    }
}

int f(int n){
    int cnt = 0;
    int i = 1;
    while (n != 1 && i<primeNum){
        if(n % prime[i] == 0){
            n/=prime[i];
            cnt++;
        }else{
            i++;
        }
    }
    if(n != 1) cnt += 1;
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    init();
    int n;
    while (cin >> n){
       cout << f(n);
    }
    return 0;
}
