//
// Created by guozhuoqiang on 2019-03-15.
//
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100000;

struct State // BFS 队列中的状态数据结构
{
    int d; // 搜索步数统计器
};

State a[maxn];

inline bool isVisited(const State &state) {
    return false;
}

inline bool CheckState(const State& s) // 约束条件检验
{
    if(isVisited(s)) return false;
    //其他条件
    //...
    return true;
}

inline bool isTarget(const State& t){
    return true;
}

inline void visit(State state) {
}

void bfs(State st)
{
    queue <State> q; // BFS 队列
    State now,next; // 定义2 个状态，当前和下一个
    st.d=0; // 计数器清零
    q.push(st); // 入队
    visit(st);
    while(!q.empty())
    {
        now=q.front(); // 取队首元素进行扩展
        q.pop(); // 队首元素出队
        if(isTarget(now)) // 出现目标态，此时为d 为搜索最小值，可以退出即可
        {
            // 做相关处理
            return;
        }
        for(int i=0;i<4;i++)
        {
            // 按照规则生成 下一个状态
            next.d=now.d+1;         // 距离加1
            if(CheckState(next))    // 如果状态满足约束条件则入队
            {
                q.push(next);
                visit(next);
            }
        }
    }
    return;
}

int main(){

    return 0;
}