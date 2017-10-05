#include <iostream>
#include <algorithm>
using namespace std;
bool isPalNum(string num){
    for(int i = 0; i < num.size() / 2; i++){
        if(num[i] != num[num.size() - 1 -i])
            return false;
    }
    return true;
}
string getNextNum(string num){
    string ret = "";
    int left = 0;
    for(int i = num.size() - 1; i >= 0; i--){
        ret += ((num[i] - '0' + num[num.size() - 1 - i] - '0') + left) % 10 + '0';
        left = ((num[i] - '0' + num[num.size() - 1 - i] - '0') + left) / 10;
    }
    if(left != 0)
        ret += left + '0';
    reverse(ret.begin(), ret.end());
    return ret;
}
int main(){
    string n;
    int k;
    cin >> n >> k;
    int i;
    for(i = 0; i < k; i++){
        // cout << n << endl;
        if(isPalNum(n)){
            cout << n << endl;
            cout << i << endl;
            return 0;
        }
        n = getNextNum(n);
    }
    cout << n << endl << i << endl;
    return 0;
}
