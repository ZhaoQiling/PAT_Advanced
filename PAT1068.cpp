#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 10100
#define MAXM 110
int w[MAXN];
int dp[MAXM];
bool isC[MAXN][MAXM];
bool mycmp(const int& a, const int& b){
    return a > b;
}
int main(){
    int nNum, tar;
    scanf("%d%d", &nNum, &tar);
    for(int i = 1; i <= nNum; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + 1 + nNum, mycmp);
    for(int i = 1; i <= nNum; i++)
        for(int j = tar; j >= w[i]; j--)
            if(dp[j] <= dp[j - w[i]] + w[i]){
                dp[j] = dp[j - w[i]] + w[i];
                isC[i][j] = true;
            }
    if(dp[tar] != tar){
        printf("No Solution");
        return 0;
    }
    int i = nNum, j = tar;
    vector<int> ans;
    while(j > 0){
        if(isC[i][j]){
            ans.push_back(w[i]);
            j -= w[i];
        }
        i--;
    }
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
