#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int people[110000];
bool isParty[110000];
int main()
{
    for(int i = 0; i < 100500; i++)
    {
        people[i] = -1;
    }
    int nCouple;
    cin >> nCouple;
    for(int i = 0; i < nCouple; i++)
    {
        int a, b;
        cin >> a >> b;
        people[a] = b;
        people[b] = a;
    }
    int nParty;
    cin >> nParty;
    vector<int> party;
    for(int i = 0; i < nParty; i++)
    {
        int id;
        cin >> id;
        isParty[id] = true;
        party.push_back(id);
    }
    vector<int> ans;
    for(int i = 0; i < nParty; i++)
    {
        if(people[party[i]] < 0)
        {
            ans.push_back(party[i]);
            continue;
        }
        if(people[party[i]] > 0 && isParty[people[party[i]]] == false)
        {
            ans.push_back(party[i]);
            continue;
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        cout << setfill('0') << setw(5) <<ans[i];
        if(i != ans.size() - 1)
            cout << " ";
    }
    return 0;
}

