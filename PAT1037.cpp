#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> cou, pro;
    int nC, nP;
    cin >> nC;
    for(int i = 0; i < nC; i++){
        int val;
        cin >> val;
        cou.push_back(val);
    }
    cin >> nP;
    for(int i = 0; i < nP; i++){
        int val;
        cin >> val;
        pro.push_back(val);
    }
    sort(cou.begin(), cou.end());
    sort(pro.begin(), pro.end());
    int sum = 0;
    for(int i = 0;i < cou.size() && i < pro.size() && cou[i] < 0 && pro[i] < 0;i++){
        sum += cou[i] * pro[i];
        // cout << sum << endl;
    }
    for(int i = 0; i < cou.size() && i < pro.size() && cou[cou.size() - 1 - i] > 0 && pro[pro.size() - 1 - i] > 0; i++){
        sum += cou[cou.size() - 1 - i] * pro[pro.size() - 1 - i];
        // cout << sum << endl;
    }
    cout << sum << endl;
}
