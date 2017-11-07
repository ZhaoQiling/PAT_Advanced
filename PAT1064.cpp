#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 99999
using namespace std;
int arr[MAXN];
int nNode;
int main(){
    memset(arr, -1, sizeof(arr));
    scanf("%d", &nNode);
    int minLoc = getMinLoc();
    return 0;
}
