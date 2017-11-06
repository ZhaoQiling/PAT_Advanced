#include <iostream>
#include <algorithm>
using namespace std;
int N;
string i2str(int val){
    if(val == 0)
        return "0";
    string ret = "";
    while(val){
        ret += char(val % 10 + '0');
        val /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string pro(const string& str){
    int begin = 0;
    for(int i = 0; i < str.size() && (str[i] == '0' || str[i] == '.'); i++)
        begin = i + 1;

    string ret = "0.";
    int cntDig = 0;
    for(int i = begin; cntDig < N; i++){
        if(i < str.size() && str[i] == '.')
            continue;

        if(i >= str.size())
            ret += '0';
        else
            ret += str[i];
        cntDig++;
    }

    int locPoint;
    for(locPoint = 0; locPoint < str.size() && str[locPoint] != '.'; locPoint++){}

    int idx = locPoint - begin;
    if(idx < 0) idx++;

    // if(idx != 0){
    if(begin == str.size())
        idx = 0;
    if(true){
        ret += "*10^";
        if(idx < 0){
            ret+= "-";
            idx = -idx;
        }
        // cout << "idx is " << idx << endl;
        ret += i2str(idx);
    }
    return ret;
}
int main(){
    string str1, str2;
    cin >> N >> str1 >> str2;
    str1 = pro(str1);
    str2 = pro(str2);
    // cout << str1 << endl << str2;
    if(str1 == str2)
        cout << "YES" << " " << str1;
    else
        cout << "NO" << " " << str1 << " " << str2;
    return 0;
}
