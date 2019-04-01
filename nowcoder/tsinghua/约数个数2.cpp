//
// Created by guozhuoqiang on 2019-03-10.
//

/*
 *
 * 素数筛法求得是 sqrt(m=1000000000) 内的素数
 * 如果一个约数>sqrt(1000000000) 则一定是素数。 反证 假设其不是素数 q = x*y 因为 sqrt(m)<q<m 有 min(x,y)<sqrt(m) 这种情况不存在 sqrt(m) 之前已经处理过了
 * 23ms
 */


#include <iostream>

using namespace std;

const int maxN = 31623;  //sqrt(maxN)  = 31622

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

int main() {
    ios::sync_with_stdio(false);
    init();
    int n, t;
    cin >> n;
    int cnt;
    int sum;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        sum = 1;
        for(int j = 1;j<primeNum;++j){
            cnt = 0;
            while (t % prime[j] == 0) {
                cnt++;
                t /= prime[j];
            }
            sum *= cnt + 1;
        }
        if(t!=1){
            sum *= 2;
        }
        cout << sum << endl;
    }
    return 0;
}
