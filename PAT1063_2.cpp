#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int main(){
    int nSet;
    scanf("%d", &nSet);
    vector<set<int> > sts(nSet + 1);
    for(int i = 1; i <= nSet; i++){
        int nNum;
        scanf("%d", &nNum);
        set<int> temp;
        for(int j = 0; j < nNum; j++){
            int val;
            scanf("%d", &val);
            temp.insert(val);
        }
        sts[i] = temp;
    }
    int nQuery;
    scanf("%d", &nQuery);
    for(int i = 0; i < nQuery; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int Nc = 0;
        int Nt = sts[a].size() + sts[b].size();
        for(set<int>::iterator ita = sts[a].begin(); ita != sts[a].end(); ++ita){
            if(sts[b].find(*ita) != sts[b].end()){
                Nc++; Nt--;
            }
        }
        printf("%.1f%%\n", Nc * 100.0 / Nt);
    }
    return 0;
}
