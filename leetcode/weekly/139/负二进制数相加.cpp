//
// Created by gzq on 6/4/19.
//
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        vector<int> ret;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int m = max(n1, n2);
        int c = 0, tmp, a, b;
        int i;
        for (i = 0; i < m; i++) {
            a = i < n1 ? arr1[i] : 0;
            b = i < n2 ? arr2[i] : 0;
            tmp = a + b + c;
            if (tmp >= 2) {
                c = -1;
                tmp -= 2;
            } else if (tmp < 0) {
                tmp += 2;
                c = 1;
            } else {
                c = 0;
            }
            ret.push_back(tmp);
        }
        if (c == 1) {
            ret.push_back(1);
        } else if (c == -1) {
            ret.push_back(1);
            ret.push_back(1);
        }
        for (int i = ret.size() - 1; i >= 0; --i) {
            if(ret[i] == 0){
                ret.pop_back();
            } else{
                break;
            }
        }
        if(ret.empty())
            return {0};
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> input11 = {1, 1, 1, 1, 1};
    vector<int> input12 = {1, 0, 1};
    vector<int> ret1 = s.addNegabinary(input11, input12);
    copy(ret1.begin(), ret1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> input21 = {0};
    vector<int> input22 = {1, 0};
    vector<int> ret2 = s.addNegabinary(input21, input22);
    copy(ret2.begin(), ret2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> input31 = {1};
    vector<int> input32 = {1};
    vector<int> ret3 = s.addNegabinary(input31, input32);
    copy(ret3.begin(), ret3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> input41 = {1};
    vector<int> input42 = {1, 1};
    vector<int> ret4 = s.addNegabinary(input41, input42);
    copy(ret4.begin(), ret4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> input51 = {1};
    vector<int> input52 = {1, 0, 1};
    vector<int> ret5 = s.addNegabinary(input51, input52);
    copy(ret5.begin(), ret5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}


