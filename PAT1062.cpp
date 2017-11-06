#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct Peo{
    Peo(){}
    Peo(int i, int v, int t, int s, int l)
        : id(i), virtue(v), talent(t), sumScore(s), level(l){}
    int id, virtue, talent;
    int sumScore, level;
};
bool cmp(const Peo& a, const Peo& b){
    if(a.level != b.level)
        return a.level < b.level;
    if(a.sumScore != b.sumScore)
        return a.sumScore > b.sumScore;
    if(a.virtue != b.virtue)
        return a.virtue > b.virtue;
    return a.id < b.id;
}
int main(){
    int nPeo, highLine, lowLine;
    scanf("%d%d%d", &nPeo, &lowLine, &highLine);
    int finalPeo = nPeo;
    vector<Peo> ranklist;
    for(int i = 0; i < nPeo; i++){
        int id, virtue, talent, sumScore, level;
        scanf("%d%d%d", &id, &virtue, &talent);
        sumScore = virtue + talent;
        if(talent >= highLine && virtue >= highLine)
            level = 1; // sages
        else if(lowLine <= talent && talent < highLine && virtue >= highLine)
            level = 2; // nobleman
        else if(talent < highLine && talent < highLine && virtue >= talent)
            level = 3; //foolman
        else
            level = 4;

        if(talent < lowLine || virtue < lowLine)
            level = 5;

        if(virtue < lowLine || talent < lowLine)
            finalPeo--;

        ranklist.push_back(Peo(id, virtue, talent, sumScore, level));
    }
    sort(ranklist.begin(), ranklist.end(), cmp);
    printf("%d\n", finalPeo);
    for(int i = 0; i < finalPeo; i++){
        printf("%08d %d %d\n", ranklist[i].id, ranklist[i].virtue, ranklist[i].talent, ranklist[i].level);
    }
    return 0;
}
