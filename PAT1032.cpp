#include <iostream>
#include <cstdio>
using namespace std;
const int ARRSIZE = 100000;
int nextLoc[ARRSIZE];
bool isVis[ARRSIZE];
int main(){
    int srcA, srcB, nNode;
    scanf("%d%d%d", &srcA, &srcB, &nNode);
    for(int i = 0; i < nNode; i++){
        int ad, ne;
        char ch;
        scanf("%d %c %d", &ad, &ch, &ne);
        nextLoc[ad] = ne;
    }
    while(srcA != -1){
        isVis[srcA] = true;
        srcA = nextLoc[srcA];
    }
    int ans = -1;
    while(srcB != -1){
        if(isVis[srcB]){
            ans = srcB;
            break;
        }
        srcB = nextLoc[srcB];
    }
    if(ans == -1)
        printf("%d", ans);
    else
        printf("%05d", ans);
    return 0;
}
