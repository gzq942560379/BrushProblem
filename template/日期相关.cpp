//
// Created by guozhuoqiang on 2019-03-15.
//
#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

//计算星期几  0 星期日  。。。
int getWeekday(int year, int m, int d) {
    if(m < 3) {
        m += 12;
        year--;
    }
    int y = year % 100;
    int c = year / 100;
    int w = (y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1) % 7;
    return w >= 0 ? w : w + 7;
}

int month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main() {
    cout << getWeekday(2049, 10, 1) << endl;
    cout << getWeekday(2006, 4, 4) << endl;
    cout << getWeekday(2019, 3, 16) << endl;
    return 0;
}
