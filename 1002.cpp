#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
double arr[1500];
int main()
{
    int nA, nB;
    cin >> nA;
    for(int i = 0; i < nA; i++)
    {
        int exp;
        double coe;
        cin >> exp >> coe;
        arr[exp] = coe;
    }
    cin >> nB;
    for(int i = 0; i < nB; i++)
    {
        int exp;
        double coe;
        cin >> exp >> coe;
        arr[exp] += coe;
    }
    int cnt = 0;
    for(int i = 1001; i >= 0; i--)
    {
        if(arr[i] != 0)
            cnt++;
    }
    cout << cnt;
    for(int i = 1001; i >= 0; i--)
    {
        if(arr[i] != 0)
        {
                //cout << i << " " << fixed << setprecision(1) << arr[i];
                printf(" %d %.1f", i, arr[i]);
        }
    }
    return 0;
}
