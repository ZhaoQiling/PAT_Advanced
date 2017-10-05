#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 99999999;
struct Stat{
    double loc;
    double price;
};
bool cmpByDis(const Stat& a, const Stat& b){
    return a.loc < b.loc;
}
int main(){
    double maxCapacity, tarDis, disPerGas;
    int nGasSta;
    cin >> maxCapacity >> tarDis >> disPerGas >> nGasSta;
    vector<Stat> stats(nGasSta + 1);
    stats[0].loc = tarDis;
    stats[0].price = 0;
    for(int i = 1; i <= nGasSta; i++)
        cin >> stats[i].price >> stats[i].loc;
    sort(stats.begin(), stats.end(), cmpByDis);
    if(stats[0].loc != 0){
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    double sumCost = 0, curDis = 0, curPrice = 0, maxReachDis = 0, leftDis = 0;
    curPrice = stats[0].price;
    while(curDis < tarDis){
        // cout << curDis << endl;
        maxReachDis = curDis + maxCapacity * disPerGas;
        bool isFindLowerPrice = false;
        double minPriceLoc = 0;
        double minPrice = INF;
        for(int i = 1; i <= nGasSta && stats[i].loc <= maxReachDis; i++){
            if(stats[i].loc <= curDis)
                continue;
            if(stats[i].price < curPrice){
                sumCost += (stats[i].loc - curDis - leftDis) / disPerGas * curPrice;
                leftDis = 0;
                curDis = stats[i].loc;
                curPrice = stats[i].price;
                isFindLowerPrice = true;
                break;
            }
            if(stats[i].price < minPrice){
                minPrice = stats[i].price;
                minPriceLoc = stats[i].loc;
            }
        }
        if(isFindLowerPrice == false && minPrice != INF){
            sumCost += (maxCapacity - leftDis / disPerGas)  * curPrice;
            leftDis = maxCapacity * disPerGas - (minPriceLoc - curDis);
            curPrice = minPrice;
            curDis = minPriceLoc;
        }
        if(isFindLowerPrice == false && minPrice == INF){
            curDis += maxCapacity * disPerGas;
            printf("The maximum travel distance = %.2f", curDis);
            return 0;
        }
    }
    printf("%.2f", sumCost);
    return 0;
}
