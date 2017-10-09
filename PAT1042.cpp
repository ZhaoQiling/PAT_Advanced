#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Card{
    Card(int i) : id(i){}
    int id;
    int loc;
};
bool cmp(const Card& a, const Card& b){
    return a.loc < b.loc;
}
int main(){
    int nTime;
    cin >> nTime;
    int oper[55];
    for(int i = 1; i <= 54; i++){
        cin >> oper[i];
    }
    vector<Card> cards;
    cards.push_back(-1);
    for(int i = 1; i <= 54; i++){
        cards.push_back(Card(i));
    }
    for(int t = 0; t < nTime; t++){
        for(int i = 1; i <= 54; i++){
            cards[i].loc = oper[i];
        }
        sort(cards.begin() + 1, cards.end(), cmp);
    }
    for(int i = 1; i <= 54; i++){
        if(i != 1)
            cout << " ";
        int id = cards[i].id - 1;
        if(id >= 0 && id <= 12){
            cout << "S" << id - 0 + 1;
        }
        else if(id >= 13 && id <= 25){
            cout << "H" << id - 13 + 1;
        }
        else if(id >= 26 && id <= 38){
            cout << "C" << id - 26 + 1;
        }
        else if(id >= 39 && id <= 51){
            cout << "D" << id - 39 + 1;
        }
        else if(id == 52)
            cout << "J1";
        else if(id == 53)
            cout << "J2";
    }
    return 0;
}
