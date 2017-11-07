#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int nSet;
    scanf("%d", &nSet);
    vector<int> sts[100];
    for(int i = 1; i <= nSet; i++){
        int nNum;
        scanf("%d", &nNum);
        for(int j = 0; j < nNum; j++){
            int val;
            scanf("%d", &val);
            // cout << "val is " << val << endl;
            sts[i].push_back(val);
        }
        sort(sts[i].begin(), sts[i].end());
    }
    // cout << "flag " << endl;
    int nQuery;
    scanf("%d", &nQuery);
    for(int k = 0; k < nQuery; k++){
        int a, b;
        scanf("%d %d", &a, &b);
        int Nc = 0, Nt = 0;
        int i = 0, j = 0;
        int prev = -1;
        while(i < sts[a].size() || j < sts[b].size()){
            if(i == sts[a].size()){
                if(sts[b][j] != prev){
                    Nt++;
                }
                prev = sts[b][j];
                j++;
                continue;
            }
            if(j == sts[b].size()){
                if(sts[a][i] != prev){
                    Nt++;
                }
                prev = sts[a][i];
                i++;
                continue;
            }
            int temp;
            if(sts[a][i] < sts[b][j]){
                temp = sts[a][i];
                i++;
            }
            else if(sts[a][i] > sts[b][j]){
                temp = sts[b][j];
                j++;
            }
            else if(sts[a][i] == sts[b][j]){
                temp = sts[a][i];
                i++; j++;
                if(temp != prev)
                    Nc++;
            }
            // cout << "---" << temp << "----";
            if(prev != temp)
                Nt++;
            prev = temp;
        }
        printf("%.1f%%\n", Nc * 100.0 / Nt);
    }
    return 0;
}
