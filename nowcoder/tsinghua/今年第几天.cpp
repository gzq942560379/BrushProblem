//
// Created by guozhuoqiang on 2019-03-11.
//


//普通闰年:能被4整除但不能被100整除的年份为普通闰年。（如2004年就是闰年，1999年不是闰年）；
//世纪闰年:能被400整除的为世纪闰年。（如2000年是世纪闰年，1900年不是世纪闰年）；

#include <iostream>

using namespace std;

bool isLeapYear(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100!= 0)){
        return true;
    }
    return false;
}

int month[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main(){
    ios::sync_with_stdio(false);
    int y,m,d;
    int flag;
    int ans;
    while (cin >> y >> m >>d){
        flag = isLeapYear(y) ? 1:0;
        ans = 0;
        for(int i =1;i<m;i++){
            ans += month[flag][i];
        }
        ans += d;
        cout << ans <<endl;
    }
    return 0;
}
