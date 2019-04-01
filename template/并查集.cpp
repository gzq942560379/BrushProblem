//
// Created by guozhuoqiang on 2019-03-15.
//


const int maxN = 100000;

int n;
int p[maxN];  //并查集数据结构

void initUF() {
    for (int i = 0; i < n; i++)
        p[i] = i;
}

int find(int ele) {
    while (ele != p[ele]) {
        ele = p[ele] = p[p[ele]];
    }
    return ele;
}

void un(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return;
    p[pb] = pa;
}

int main(){
    return 0;
}