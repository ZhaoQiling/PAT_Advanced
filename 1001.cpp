#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int nAns = a + b;
    stringstream ss;
    ss << nAns;
    string sAns;
    ss >> sAns;
    bool isNage;
    int start;
    if(sAns[0] == '-')
    {
        isNage = true;
        start = 1;
    }
    else
    {
        isNage = false;
        start = 0;
    }
    int loc = 0;
    vector<char> arr;
    for(int i = sAns.size() - 1; i >= start; i--)
    {
        arr.push_back(sAns[i]);
        loc++;
        if(loc == 3 && i != start)
        {
            arr.push_back(',');
            loc = 0;
        }
    }
    if(isNage)
        arr.push_back('-');
    for(int i = arr.size() - 1; i >= 0; i--)
        cout << arr[i];
    return 0;
}

