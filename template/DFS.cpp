//
// Created by guozhuoqiang on 2019-03-15.
//

#include <iostream>
#include <algorithm>
struct State{

};

bool isTarget(const State &state) {
    return false;
}
bool isVisited(const State& state){
    return true;
}

void visit(const State& state){

}

bool check(const State& state){
    return false;
}

void dfs(State now){
    if(isVisited(now)){
        return;
    }
    visit(now);
    if(isTarget(now)){
        //...
        return;
    }
    for(int i = 0;i<10;i++){ //向下扩展
        State newState;
        if(!check(newState)) continue;   //剪枝处理
        dfs(newState);
    }
}

int main(){
    //input
    //State start
    //dfs(start)
    return 0;
}