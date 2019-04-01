//
// Created by guozhuoqiang on 2019-03-15.
//

#include <algorithm>

//state 往往为全局变量

using namespace std;

struct State{

};

bool IsEnd(const State& s){

}

int GetVal(const State& s){
    return 0;
}



inline int dfs(State s,int Alpha,int Beta,int Which)//Status记录当前状态，Which记录当前操作的选手，其中0号选手取Max，1号选手取Min
//Alpha存储较大值，Beta存储较小值
//如果当前节点是取Max的节点，则Alpha表示当前节点父亲的父亲的权值，Beta表示当前节点父亲的权值
//如果当前节点是取Min的节点，则Alpha表示当前节点父亲的权值，Beta表示当前节点父亲的父亲的权值
{
    if(IsEnd(s)) return GetVal(s);//如果当前状态已经为最终状态，就返回当前状态的分值
    State newState;
    int t;
    for(int i=1;i<=10;++i)//枚举从当前状态能够扩展到的新状态
    {
        t=dfs(newState,Alpha,Beta,Which^1);//求出当前枚举到的新状态的分值
        Which?Beta=min(Beta,t):Alpha=max(Alpha,t); //如果当前节点取min，就更新Beta，否则更新Alpha
        if(Alpha>=Beta) break;//如果Alpha≥Beta，就说明这个节点对最终答案没有贡献了，就结束搜索
    }
    return Which?Beta:Alpha;//返回相应值
}

int main(){

    return 0;
}