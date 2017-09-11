#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    int nNum;
    cin >> nNum;
    int nCount = 0;
    double sum = 0;
    int order = 0;
    for(int order = 0; order != nNum; order++)
    {
        string s;
        cin >> s;
        int start = 0;
        if(s[0] == '-')
            start = 1;
        bool isLeg = true;
        int locPoint = s.length();
        for(int i = start; i < s.length(); i++)
        {
            if((s[i] < '0' || s[i] > '9') && s[i] != '.')
            {
                isLeg = false;
                break;
            }
            if(s[i] == '.' && locPoint != s.length())
            {
                isLeg = false;
                break;
            }
            if(s[i] == '.')
                locPoint = i;
        }
        if(isLeg == false)
        {
            cout << "ERROR: " << s << " is not a legal number" << endl;
            continue;
        }
        int countBefore = locPoint - start;
        int beforePoint = 0;
        int countAfter = s.length() - 1 - locPoint;
        int afterPoint = 0;
        for(int i = start; i < locPoint; i++)
        {
            beforePoint = beforePoint * 10 + s[i] - '0';
        }
        for(int i = locPoint + 1; i < s.length(); i++)
        {
            afterPoint = afterPoint * 10 + s[i] - '0';
        }
        if(beforePoint > 1000 || countAfter > 2)
        {
            cout << "ERROR: " << s << " is not a legal number" << endl;
            continue;
        }
        double val = 0;
        val += beforePoint;
        if(countAfter == 1)
            val += afterPoint * 0.1;
        else if(countAfter == 2)
            val += afterPoint * 0.01;
        //cout << ": " << val << endl;
        if(start == 1)
            val *= -1;
        if(val > 1000 || val < -1000)
        {
            cout << "ERROR: " << s << " is not a legal number" << endl;
            continue;
        }
        sum += val;
        nCount++;
    }
    if(nCount == 0)
    {
        cout << "The average of 0 numbers is Undefined";
    }
    else if(nCount == 1)
    {
        cout << "The average of 1 number is " << fixed << setprecision(2) << sum / nCount;
    }
    else{
         cout << "The average of " << nCount << " numbers is " << fixed << setprecision(2) << sum / nCount;
    }
    return 0;
}
