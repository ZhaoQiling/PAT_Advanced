#include <cstdio>
#include <stack>
using namespace std;
const int arrSize = 100100;
int bit[arrSize];
int lowbit(int x){
    return x & -x;
}
void update(int loc, int val){
    while(loc < arrSize){
        bit[loc] += val;
        loc += lowbit(loc);
    }
}
int read(int loc){
    int sum = 0;
    while(loc > 0){
        sum += bit[loc];
        loc -= lowbit(loc);
    }
    return sum;
}
int main(){
    int nNum;
    scanf("%d", &nNum);
    stack<int> stk;
    while(nNum--){
        char oper[10];
        scanf("%s", oper);
        //Pop
        if(oper[1] == 'o'){
            if(stk.empty())
                printf("Invalid\n");
            else{
                update(stk.top(), -1);
                printf("%d\n", stk.top());
                stk.pop();
            }
        }
        //PeekMedian
        else if(oper[1] == 'e'){
            if(stk.empty()){
                printf("Invalid\n");
                continue;
            }
            int tar = (stk.size() + 1) / 2;
            int left = 1;
            int right = arrSize;
            while(left < right){
                int mid = (left + right) / 2;
                if(read(mid) >= tar)
                    right = mid;
                else
                    left = mid + 1;
            }
            printf("%d\n", left);
        }
        //Push
        else if(oper[1] == 'u'){
            int val;
            scanf("%d", &val);
            stk.push(val);
            update(stk.top(), 1);
        }
    }
    return 0;
}
