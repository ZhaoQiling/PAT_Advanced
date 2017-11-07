#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 2000
using namespace std;
int nNode;
int curSeq = 0;
vector<int> seq;
int arr[MAXN];
void dfs(int root){
    if(root > nNode)
        return;
    dfs(root << 1);
    arr[root] = seq[curSeq++];
    dfs(root << 1 | 1);
}
int main(){
    scanf("%d", &nNode);
    seq.resize(nNode);
    for(int i = 0; i < nNode; i++)
        scanf("%d", &seq[i]);
    sort(seq.begin(), seq.end());
    dfs(1);

    for(int i = 1; i <= nNode; i++){
        if(i != 1) printf(" ");
        printf("%d", arr[i]);
    }
    return 0;
}
