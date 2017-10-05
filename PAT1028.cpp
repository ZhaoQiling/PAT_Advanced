#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Stu{
    int id;
    char name[50];
    int score;
};
bool cmp1(const Stu& a, const Stu& b){
    return a.id < b.id;
}
bool cmp2(const Stu& a, const Stu& b){
    int flag = strcmp(a.name, b.name);
    if(flag != 0)
        return flag < 0;
    return a.id < b.id;
}
bool cmp3(const Stu& a, const Stu& b){
    if(a.score != b.score)
        return a.score < b.score;
    return a.id < b.id;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    int nRow, colNum;
    scanf("%d%d", &nRow, &colNum);
    // cin >> nRow >> colNum;
    vector<Stu> namelist;
    namelist.resize(nRow);
    for(int i = 0; i < nRow; ++i){
        scanf("%d %s %d", &namelist[i].id, &namelist[i].name, &namelist[i].score);
        // cin >> namelist[i].id
        //     >> namelist[i].name
        //     >> namelist[i].score;
    }
    if(colNum == 1)
        sort(namelist.begin(), namelist.end(), cmp1);
    else if(colNum == 2)
        sort(namelist.begin(), namelist.end(), cmp2);
    else if(colNum == 3)
        sort(namelist.begin(), namelist.end(), cmp3);
    for(int i = 0; i < nRow; ++i){
        // cout << setw(6) << setfill('0') << namelist[i].id << " ";
        // cout << namelist[i].name << " " << namelist[i].score << endl;
        printf("%06d %s %d\n", namelist[i].id, namelist[i].name, namelist[i].score);
    }
    return 0;
}
