//
// Created by gzq on 4/23/19.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <iterator>

// 简单计算器 实现 +-×/ () 整数(包括负号)运算

using namespace std;

struct Node {
    bool isOp;
    union {
        double number;
        char op;
    };

    explicit Node(int val) : isOp(false), number(val) {}

    explicit Node(double val) : isOp(false), number(val) {}

    explicit Node(char op) : isOp(true), op(op) {}

    Node() = default;
};

const map<char, int> opMap{
        make_pair('+', 0),
        make_pair('-', 0),
        make_pair('*', 1),
        make_pair('/', 1),
};

// 计算后缀表达式
double computeSuffixExp(const vector<Node> &suffixExp);

// 中缀转后缀
void convertToSuffixExp(const vector<Node> &exp, vector<Node> &suffixExp);

// 计算无括号的表达式
double computeExp(const vector<Node> &exp);

// 解析同时处理括号  及 负号只会出现在 第一个字符或括号后的第一个字符 两种情况
double computeStr(const string &expStr);

int main() {
    cout << computeStr("12+78/4*6*7/3-12-13-24*25/6") << endl;
    cout << computeStr("5+2*3/49-4/13") << endl;
    cout << computeStr("3*(2+5)") << endl;
    cout << computeStr("-5*(-3)");
    return 0;
}

double computeSuffixExp(const vector<Node> &suffixExp) {
    stack<double> s;
    for (const Node &node:suffixExp) {
        if (node.isOp) {
            double val2 = s.top();
            s.pop();
            double val1 = s.top();
            s.pop();
            double val = 0;
            switch (node.op) {
                case '+':
                    val = val1 + val2;
                    break;
                case '-':
                    val = val1 - val2;
                    break;
                case '*':
                    val = val1 * val2;
                    break;
                case '/':
                    val = val1 / val2;
                    break;
                default:
                    cerr << "error for op : " << node.op << endl;
                    exit(-1);
            }
            s.push(val);
        } else {
            s.push(node.number);
        }
    }
    return s.top();
}

double computeStr(const string &expStr) {
    vector<Node> exp;
    stack<int> s;
    bool hasVal = false;
    int val = 0;
    bool negative = false;
    int i = 0;
    //处理负数
    if (expStr[i] == '-') {
        negative = true;
        i++;
    }
    for (; i < expStr.size(); i++) {
        char ch = expStr[i];
        if (ch >= '0' && ch <= '9') {
            hasVal = true;
            val = val * 10 + ch - '0';
        } else {
            if (hasVal) {
                if (negative) val = -val;
                exp.emplace_back(val);
                val = 0;
                hasVal = false;
                negative = false;
            }
            if (ch == '(') {
                s.push(exp.size());
                //处理负数
                if (expStr[i + 1] == '-') {
                    negative = true;
                    i++;
                }
            } else if (ch == ')') {
                auto start = exp.begin();
                advance(start, s.top());
                vector<Node> innerExp(distance(start, exp.end()));
                copy(start, exp.end(), innerExp.begin());
                exp.erase(start, exp.end());
                exp.emplace_back(computeExp(innerExp));
                s.pop();
            } else if (opMap.find(ch) != opMap.end()) {
                exp.emplace_back(ch);
            }

        }
    }
    if (hasVal) {
        exp.emplace_back(val);
    }
    return computeExp(exp);
}

double computeExp(const vector<Node> &exp) {
    vector<Node> suffixExp;
    convertToSuffixExp(exp, suffixExp);
    return computeSuffixExp(suffixExp);
}

void convertToSuffixExp(const vector<Node> &exp, vector<Node> &suffixExp) {
    suffixExp.clear();
    stack<Node> opStack;
    for (const Node &node:exp) {
        if (node.isOp) {
            while (!opStack.empty() && opMap.at(opStack.top().op) >= opMap.at(node.op)) {
                suffixExp.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(node);
        } else {
            suffixExp.push_back(node);
        }
    }
    while (!opStack.empty()) {
        suffixExp.push_back(opStack.top());
        opStack.pop();
    }
}
