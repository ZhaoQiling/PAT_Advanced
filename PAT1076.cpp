#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 1100
int edge[MAXN][MAXN];
int isVis[MAXN];
struct Node{
    int loc, step;
    Node(int l, int s)
    : loc(l), step(s){}
};
int nVertex, level;
int bfs(int start){
    memset(isVis, 0, sizeof(isVis));
    int ret = 0;
    queue<Node> que;
    que.push(Node(start, 0));
    isVis[start] = 1;
    while(!que.empty()){
        Node frt = que.front();
        que.pop();
        for(int i = 1; i <= nVertex; i++){
            if(!edge[frt.loc][i] || isVis[i])
                continue;
            if(frt.step >= level)
                continue;
            isVis[i] = 1;
            que.push(Node(i, frt.step + 1));
            ret++;
        }
    }
    return ret;
}
int main(){
    scanf("%d %d", &nVertex, &level);

    for(int i = 1; i <= nVertex; i++){
        int u; scanf("%d", &u);
        for(int j = 0; j < u; j++){
            int v; scanf("%d", &v);
            edge[v][i] = 1;
        }
    }
    int nQuery; scanf("%d", &nQuery);
    for(int i = 0; i < nQuery; i++){
        int u; scanf("%d", &u);
        printf("%d\n", bfs(u));
    }
    return 0;
}
