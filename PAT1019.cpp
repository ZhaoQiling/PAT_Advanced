#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<int> getVecNum(int num, int base){
    std::vector<int> sv;
    while(num){
        sv.push_back(num % base);
        num /= base;
    }
    if(sv.size() != 0)
        reverse(sv.begin(), sv.end());
    return sv;
}
bool isPal(const vector<int> & vc){
    for(int i = 0; i < vc.size() / 2; i++){
        if(vc[i] != vc[vc.size() - 1 - i])
            return false;
    }
    return true;
}
int main(){
    int num, base;
    cin >> num >> base;
    vector<int> vecNum = getVecNum(num, base);
    // for(int i = 0; i < vecNum.size(); ++i){
    //     cout << vecNum[i] << " ";
    // }
    if(isPal(vecNum))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    for(int i = 0; i < vecNum.size(); i++){
        if(i != 0) cout << " ";
            cout << vecNum[i];
    }
    if(vecNum.size() == 0)
        cout << "0";

}
