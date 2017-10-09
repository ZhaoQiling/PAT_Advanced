#include <iostream>
#include <vector>
using namespace std;
bool isCh[2000];
int main(){
    int nStr;
    cin >> nStr;
    vector<string> account;
    vector<string> password;
    int cnt = 0;
    for(int i = 0; i < nStr; i++){
        string a, p;
        cin >> a >> p;
        account.push_back(a);
        bool flag = false;
        for(int j = 0; j < p.size(); j++){
            if(p[j] == '1'){ p[j] = '@'; flag = true;}
            else if(p[j] == '0'){ p[j] = '%'; flag = true;}
            else if(p[j] == 'l'){ p[j] = 'L'; flag = true;}
            else if(p[j] == 'O'){ p[j] = 'o'; flag = true;}
        }
        if(flag == true){
            cnt++;
            isCh[i] = true;
        }
        password.push_back(p);
    }
    if(cnt == 0){
        if(nStr == 1)
            cout << "There is " << nStr << " account and no account is modified" << endl;
        else
            cout << "There are " << nStr << " accounts and no account is modified" << endl;
        return 0;
    }
    cout << cnt << endl;
    for(int i = 0; i < nStr; i++){
        if(isCh[i] == false)
            continue;
        cout << account[i] << " " << password[i] << endl;
    }
}
