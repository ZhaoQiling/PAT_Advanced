#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int arrSize = 99999;
char isPrime[arrSize];
int cnt[arrSize];
void processPrime(){
    isPrime[1] = 0;
    for(int i = 2; i < arrSize; i++){
        for(int j = 2; i * j < arrSize; j++){
            isPrime[i * j] = 0;
        }
    }
}
int main(){
    memset(isPrime, 1, sizeof(isPrime));
    memset(cnt, 0, sizeof(cnt));
    processPrime();
    // for(int i = 1; i < arrSize; i++)
    //     if(isPrime[i])
    //         printf("%d ", i);
    long long value;
    scanf("%d", &value);
    printf("%lld=", value);
    if(value == 1){
        printf("1");
        return 0;
    }
    for(long long i = 2; i < arrSize; i++){
        while(value % i == 0){
            cnt[i]++;
            value /= i;
        }
    }
    int flag = 0;
    for(int i = 2; i < arrSize; i++){
        if(cnt[i] == 0)
            continue;
        if(flag)
            printf("*");
        printf("%d", i);
        if(cnt[i] != 1)
            printf("^%d", cnt[i]);
        flag = 1;
    }
    return 0;
}
