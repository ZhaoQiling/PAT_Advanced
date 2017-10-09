#include <cstdio>
#include <vector>
using namespace std;
int cntNum[10010];
int main(){
    int nNum;
    scanf("%d", &nNum);
    vector<int> savNum;
    for(int i = 0; i < nNum; i++){
        int num;
        scanf("%d", &num);
        cntNum[num]++;
        savNum.push_back(num);
    }
    for(int i = 0; i < nNum; i++){
        if(cntNum[savNum[i]] == 1){
            printf("%d", savNum[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}
