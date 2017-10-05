#include <iostream>
#include <iomanip>
using namespace std;
string getMar(int val){
    int a = val / 13;
    int b = val % 13;
    string s = "";
    if(a >= 10)
        s += a - 10 + 'A';
    else
        s += a + '0';

    if(b >= 10)
        s += b - 10 + 'A';
    else
        s += b + '0';
    return s;
}
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << "#";
    cout << fixed << setw(2) << setfill('0') << getMar(a) << getMar(b) << getMar(c);
    return 0;
}
