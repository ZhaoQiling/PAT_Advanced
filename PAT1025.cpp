#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 30100;
//registration_number final_rank location_number local_rank
struct Stu{
    Stu(int s, string str, int ln)
        : score(s), res_str(str), loc_num(ln){};
    int score;
    string res_str;
    int loc_num;
    int loc_rank;
    int final_rank;
};
bool cmp(const Stu& a, const Stu& b){
    if(a.score != b.score)
        return a.score > b.score;
    return a.res_str < b.res_str;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int nLoc;
    cin >> nLoc;
    vector<Stu> finalList;
    for(int loc = 1; loc <= nLoc; loc++){
        int nStu;
        cin >> nStu;
        for(int j = 0; j < nStu; j++){
            string res_str;
            int score;
            cin >> res_str >> score;
            finalList.push_back(Stu(score, res_str, loc));
        }
    }

    sort(finalList.begin(), finalList.end(), cmp);

    vector<int> savLoc(finalList.size() + 10);
    vector<int> cntLoc(finalList.size() + 10);
    for(int i = 0; i < finalList.size() + 10; i++){
        savLoc[i] = 0;
        cntLoc[i] = 0;
    }

    for(int i = 0; i < finalList.size(); i++){
        //成绩不相等 或者 第一个
        if(cntLoc[finalList[i].loc_num] == 0
            || finalList[savLoc[finalList[i].loc_num]].score != finalList[i].score){
            finalList[i].loc_rank = cntLoc[finalList[i].loc_num] + 1;
        }
        //成绩相等
        else{
            finalList[i].loc_rank = finalList[savLoc[finalList[i].loc_num]].loc_rank;
        }
        savLoc[finalList[i].loc_num] = i;
        cntLoc[finalList[i].loc_num]++;

        if(i == 0)
            finalList[i].final_rank = 1;
        else if(finalList[i].score == finalList[i - 1].score)
            finalList[i].final_rank = finalList[i - 1].final_rank;
        else
            finalList[i].final_rank = i + 1;
    }

    cout << finalList.size() << endl;
    for(int i = 0; i < finalList.size(); i++){
        cout << setw(13) << setfill('0') << finalList[i].res_str;
        cout << " " << finalList[i].final_rank << " "
            << finalList[i].loc_num << " " << finalList[i].loc_rank << endl;
    }
    return 0;
}
