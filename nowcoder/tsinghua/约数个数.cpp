//
// Created by guozhuoqiang on 2019-03-10.
//

/*
 * 朴素做法 运行很慢
 * 87ms
 */
#include <iostream>

using namespace std;

const int maxN= 1001;
const int MAX = 1000000000;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        int count = 0;
        int j;
        for(j = 1;j*j < t;j++){
            if(t % j == 0){
                count+=2;
            }
        }
        if(j*j == t){
            count+=1;
        }
        cout << count << endl;
    }
    return 0;
}
