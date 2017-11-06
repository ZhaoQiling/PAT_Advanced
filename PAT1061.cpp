#include <iostream>
#include <cstdio>
using namespace std;
string wkds[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(){
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int startH;
    for(int i = 0; i < a.size() && i < b.size(); i++){
        if(a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G'){
            cout << wkds[a[i] - 'A'] << " ";
            startH = i;
            break;
        }
    }
    for(int i = startH + 1; i < a.size() && i < b.size(); i++){
        if(a[i] != b[i])
            continue;
        if(a[i] >= '0' && a[i] <= '9'){
            printf("%02d:", a[i] - '0');
            break;
        }
        else if(a[i] >= 'A' && a[i] <= 'N'){
            printf("%d:", a[i] - 'A' + 10);
            break;
        }
    }

    for(int i = 0; i < c.size() && i < d.size(); i++){
        if(c[i] == d[i] &&
            ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
