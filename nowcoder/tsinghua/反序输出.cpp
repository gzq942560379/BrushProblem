//
// Created by guozhuoqiang on 2019-03-10.
//

#include <iostream>

using namespace std;
char s[4];

int main(){
    ios::sync_with_stdio(false);
    while(cin >> s){
        cout << s[3]<<s[2]<<s[1]<<s[0] << endl;
    }
    return 0;
}