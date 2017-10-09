#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool aFuckingAmazingCmp(const string& a, const string& b){
    return a + b < b + a;
}
int main(){
    int nNum;
    cin >> nNum;
    vector<string> arr;
    for(int i = 0; i < nNum; i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), aFuckingAmazingCmp);
    string s = "";
    for(int i = 0; i < nNum; i++)
        s += arr[i];
    while(s.size() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.size() == 0)
        cout << 0 << endl;
    else
        cout << s << endl;
    return 0;
}
