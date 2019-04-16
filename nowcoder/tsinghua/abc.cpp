//
// Created by guozhuoqiang on 2019-03-11.
//
#include <iostream>
#include <algorithm>

int main(){
    for(int a =1;a<10;a++){
        for(int b = 1;b<10;b++){
            for(int c= 0;c<10;c++){
                if(a*100+b*10+c+b*100+c*10+c == 532){
                    std::cout << a<<" "<<b<<" "<<c <<std::endl;
                }
            }
        }
    }
    return 0;
}
