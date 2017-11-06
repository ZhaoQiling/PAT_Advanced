#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Peo{
    Peo(int i, int v, int t)
        : id(i), virtue(v), talent(t){};
    int id, virtue, talent;
    int sumScore, level;
}temp;
bool cmp(const Peo& a, const Peo& b){

}
int main(){
    int nPeo, highLine, lowLine;
    scanf("%d%d%d", &nPeo, &highLine, &lowLine);
    vector<int> ranklist;
    for(int i = 0; i < nPeo; i++){
        scanf("%d%d%d", &temp.id, temp.virtue, &temp.talent);
        temp.sumScore = temp.virtue + temp.talent;
        if(temp.virtue >= highLine && temp.talent >= highLine)
            temp.level = 1;
        else if(temp.talent < highLine && temp.talent >= lowLine && temp.virtue >= highLine)
            temp.level = 2;
        else if(temp.talent >= lowLine && temp.virtue >= lowLine)
            temp.level = 3;
        else
            temp.level = 4;

        ranklist.push_back(temp);
    }
    sort(ranklist.begin(), ranklist.end(), cmp);
    return 0;
}
