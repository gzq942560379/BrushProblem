//
// Created by guozhuoqiang on 2019-03-11.
//
#include <iostream>

using namespace std;

const int maxN = 1000000;

int n,mx,dp,A;

int main(){
    ios::sync_with_stdio(false);
    while(cin >> n){
        cin >> A;
        dp = A;
        mx = A;
        for(int i = 1;i< n;i++){
            cin >> A;
            dp = max(dp+A,A);
            mx = max(dp,mx);
        }
        cout << mx <<endl;
    }
    return 0;
}
