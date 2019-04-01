#include <iostream>
#include <vector>
#include <string>
#include "Min.h"


using namespace std;

int main() {
    vector<int> v;
    int a = 1, b = 2;
    Min<int> m;

    cout << m.min(a, b);
    return 0;
}