//
// Created by gzq on 4/26/19.
//
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
int lower_bound(T *t, int l, int r, T value) {
    while (r > l) {
        int m = (l + r) / 2;
        if (t[m] < value) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

template<typename T>
int upper_bound(T *t, int l, int r, T value) {
    while (r > l) {
        int m = (l + r) / 2;
        if (value < t[m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

template<typename T>
bool binary_search(T *t, int l, int r, T value) {
    while (r > l) {
        int m = (l + r) / 2;
        if (t[m] < value) {
            l = m + 1;
        } else if (value < t[m]) {
            r = m;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int a[]{1, 2, 3, 5, 5, 5, 7, 8, 9};
    cout << lower_bound(a, 0, 8, 5) << endl;
    cout << upper_bound(a, 0, 8, 5) << endl;
    cout << binary_search(a, 0, 8, 5) << endl;


    return 0;
}
