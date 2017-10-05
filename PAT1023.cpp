#include <iostream>
using namespace std;
int stat0[10];
int stat1[10];
int main(){
    string s;
    cin >> s;
    string ans;
    int left = 0;
    for(int i = s.size() - 1; i >= 0; --i){
        ans += (2 * (s[i] - '0') + left) % 10 + '0';
        left = (2 * (s[i] - '0') + left) / 10;
    }
    if(left != 0)
        ans += left + '0';

    for(int i = 0; i < s.size(); i++){
        stat0[s[i] - '0']++;
    }
    for(int i = 0; i < ans.size(); i++){
        stat1[ans[i] - '0']++;
    }
    bool flag = true;
    for(int i = 0; i < 10; i++){
        if(stat0[i] != stat1[i]){
            flag = false;
            break;
        }
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    for(int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i];
    return 0;
}
