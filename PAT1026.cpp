#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 999999;
struct Player{
    int arriveTime, playTime;
    int startTime;
    bool isVip;
}tempPlayer;
vector<Player> player;
struct Table{
    int endTime = 8 * 60 * 60;
    int cntPlayer = 0;
    bool isVip = false;
};
vector<Table> table;
bool cmpArriveTime(const Player& a, const Player& b){
    return a.arriveTime < b.arriveTime;
}
int findIdleTable(){
    int minEndTime = INF;
    int ret = -1;
    for(int i = 0; i < table.size(); i++){
        if(table[i].endTime < INF){
            minEndTime = table[i].endTime;
            ret = i;
        }
    }
    return ret;
}
int findNextVipPlayer(int loc){
    loc++;
    while(loc < player.size() && player[loc].isVip == false)
        loc++;
    if(loc == player.size())
        return -1;
    return loc;
}
int main(){
    int nPlayer;
    cin >> nPlayer;
    player.resize(nPlayer);
    for(int i = 0; i < nPlayer; i++){
        int h, m, s, p, v;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &v);
        tempPlayer.arriveTime = h * 60 * 60 + m * 60 + s;
        tempPlayer.playTime = (p <= 120 ? p : 120) * 60;
        tempPlayer.isVip = v == 1 ? true : false;
    }
    sort(player.begin(), player.end(), cmpArriveTime);
    int nTable, nVipTable;
    cin >> nTable >> nVipTable;
    table.resize(nTable);
    for(int i = 0; i < nVipTable; i++){
        int val;
        cin >> val;
        table[val - 1].isVip = true;
    }

    int locPlayer = 0;
    int nextVIPPlayer = -1
    while(locPlayer < player.size()){
        int locTable = findIdleTable();
        int minEndTime = table[locTable].endTime;
        if(minEndTime > 21 * 60 * 60)
            break;
        if(table[locTable] == true){
            if()
            int nextVIPPlayer = findNextVipPlayer(nextVIPPlayer);
            if(nextVIPPlayer == -1
                || player[nextVIPPlayer].arriveTime > table[locTable].endTime){
                allocTable(nextVIPPlayer, locTable);
            }
            else if(player[nextVIPPlayer].arriveTime <= table[locTable].endTime){
                allocTable(i, locTable);
            }
        }
        else if(table[locTable] == false){

        }
    }

    return 0;
}
