#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    int ans = 0;
    for(int i = 0; i < str.size(); i++){
        for(int j = i; j < str.size(); j++){
            bool flag = true;
            for(int k = 0; k <= (j - i) / 2; k++){
                if(str[i + k] != str[j - k]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans;
    return 0;
}
