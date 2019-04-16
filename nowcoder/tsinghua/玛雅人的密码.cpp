//
// Created by guozhuoqiang on 2019-03-10.
//

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    string s;
    int d;
};

int n;
unordered_set<string> vis;


int bfs(string ss) {
    Node *start, *u, *v;
    start = new Node();
    start->s = ss;
    start->d = 0;
    vis.clear();
    if (start->s.find("2012") != string::npos) {
        return 0;
    }
    queue<Node *> q;
    vis.insert(start->s);
    q.push(start);
    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            string vs = u->s;
            swap(vs[i - 1], vs[i]);
            if (vis.find(vs) != vis.end()) {
                continue;
            }
//                free(u);
            v = new Node();
            v->s = vs;
            v->d = u->d + 1;
            if (v->s.find("2012") != string::npos) {
                return v->d;
            }
            vis.insert(v->s);
            q.push(v);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    string t;
    while (cin >> n) {
        cin >> t;
        cout << bfs(t) << endl;
    }
    return 0;
}
