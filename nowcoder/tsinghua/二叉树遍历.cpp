//
// Created by guozhuoqiang on 2019-03-10.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxL = 101;

char s[maxL];
int len;
int i;

struct Node {
    char ch;
    Node *left;
    Node *right;
};

Node *buildTree() {
    if (i >= len) {
        return NULL;
    }
    if (s[i] == '#') {
        i += 1;
        return NULL;
    }
    Node *n = new Node();
    n->ch = s[i];
    i += 1;
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
void inOrder(const Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->ch << " ";
    inOrder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> s) {
        len = strlen(s);
        i = 0;
        Node *root = buildTree();
        inOrder(root);
        cout << endl;
    }
    return 0;
}