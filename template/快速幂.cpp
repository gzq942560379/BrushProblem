//
// Created by guozhuoqiang on 2019-03-11.
//
#include <iostream>

using namespace std;

long long fpow(int a,int b){
    long long ans = 1,base=a;
    while (b>0){
        if(b&1==1)
            ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}


int main(){
    cout << fpow(4,4) <<endl;
    return 0;
}
