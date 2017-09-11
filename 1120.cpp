#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int nNum;
    cin >> nNum;
    vector<int> ans;
    for(int i = 0; i < nNum; i++)
    {
        string s;
        cin >> s;
        int total = 0;
        for(int i = 0; i < s.length(); i++)
            total += s[i] - '0';
        ans.push_back(total);
    }
    sort(ans.begin(), ans.end());
    int total = 1;
    for(int i = 1; i < ans.size(); i++)
    {
        if(ans[i] != ans[i - 1])
            total++;
    }
    cout << total << endl;
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++)
    {
        if(ans[i] != ans[i - 1])
        {
            cout << " " << ans[i];
        }
    }
    return 0;
}
