#include <cstdio>
#include <cstring>
#define MAXN 100100
using namespace std;
int arr[MAXN];
int cnt[MAXN];
int getFather(int a){
    if(a == arr[a])
        return a;
    return arr[a] = getFather(arr[a]);
}
void merge(int a, int b){
    a = getFather(a);
    b = getFather(b);
    if(a < b)
        arr[b] = a;
    else
        arr[a] = b;
}
int main(){
    int nNum;
    scanf("%d", &nNum);
    for(int i = 0; i < nNum; arr[i] = i++);
    for(int i = 0; i < nNum; i++)
        arr[i] = i;

    for(int i = 0; i < nNum; i++){
        int val;
        scanf("%d", &val);
        merge(i, val);
    }

    for(int i = 0; i < nNum; i++){
        cnt[arr[i]]++;
    }

    int sum = 0;
    for(int i = 0; i < nNum; i++){
        if(arr[i] != i)
            continue;
        sum += cnt[i] - 1;
        if(i != 0 && cnt[i] != 1)
            sum += 2;
    }
    printf("%d", sum);
    return 0;
}
