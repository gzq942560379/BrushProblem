#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define rep(i,s,e) for(int i = s;i<e;i++)

using namespace std;

const int maxL = 81;
const int maxN = 101;

struct Node {
    int level,p;
    char ele[maxL];
    char id[maxL];
};

int n,m;
Node node[maxN];

void split(char* s,const char* d,vector<char*>& ret){
    char* t = strtok(s, d);
    while(t != NULL){
        ret.push_back(t);
        t = strtok(NULL, d);
    }
}

//原地转换
char* strtolower(char* s){
    size_t len = strlen(s);
    rep(i,0,len){
        if(s[i]>='A' && s[i] <= 'Z'){
            s[i] -= 32;
        }
    }
    return s;
}

bool matchOne(const char * pattern,const Node& node){
    if (pattern[0] == '#') {
        return strcmp(pattern, node.id) == 0;
    }else{
        return strcmp(pattern, node.ele) == 0;
    }
}

int main(){
    // input
    char temp[maxL];
    scanf("%d %d\n",&n,&m);
    vector<char*> tv;
    rep(i,0,n){
        fgets(temp,maxL, stdin);
        temp[strlen(temp)-1]='\0';
        int j = 0;
        while(temp[j] == '.'){
            j++;
        }
        node[i].level = j >> 1;
        split(temp+j, " ", tv);
        strcpy(node[i].ele, strtolower(tv.at(0)));
        if(tv.size() > 1) strcpy(node[i].id, tv.at(1));
        tv.clear();
    }
    // init parent;
    node[0].p = -1;
    rep(i,1,n){
        int plevel = node[i].level - 1;
        for(int j = i -1;j >= 0;j--){
            if(plevel == node[j].level){
                node[i].p = j;
                break;
            }
            node[i].p = -1;
        }
    }
    int counter = 0;
    queue<int> path;
    // query
    while (m--) {
        fgets(temp,maxL, stdin);
        temp[strlen(temp)-1]='\0';
        split(temp, " ", tv);
        counter = 0;
        if(tv.size()==1){
            char* pattern = tv.at(0);
            rep(i,0,n){
                if(matchOne(pattern,node[i])){
                    counter++;
                    path.push(i);
                }
            }
        }else{
            rep(i, 0, n){
                char* pattern =tv.at(tv.size()-1);
                //如果子元素 与 node i 匹配 则不断向前匹配
                if(!matchOne(pattern, node[i])){
                    continue;
                }
                int p = node[i].p;
                int j = (int)tv.size()-2;
                while (p != -1 && j >= 0) {
                    pattern = tv.at(j);
                    if(matchOne(pattern, node[p])){
                        j--;
                    }
                    p = node[p].p;
                }
                if(j < 0){
                    counter++;
                    path.push(i);
                }
            }
        }
        //output
        printf("%d",counter);
        rep(i, 0, counter){
            printf(" %d",path.front()+1);
            path.pop();
        }
        printf("\n");
        tv.clear();
    }
    //    getchar();
    return 0;
}


/*
 11 5
 HTML
 ..head
 ....title
 ..body
 ....h1
 ....p #subtitle
 ....div #main
 ......h2
 ......p #one
 ......div
 ........p #two
 p
 h1 #subtitle
 h3
 div p
 div div p
 
 */
