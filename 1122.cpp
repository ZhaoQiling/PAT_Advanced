#include <iostream>
#include <vector>
using namespace std;
bool graph[250][250];
bool isVisit[250];
int main()
{
    int nVer, nEdge;
    cin >> nVer >> nEdge;
    for(int i = 0; i < nEdge; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    int nQuery;
    cin >> nQuery;
    for(int query = 1; query <= nQuery; query++)
    {
        int nPath;
        cin >> nPath;
        vector<int> path;
        for(int i = 0; i < nPath; i++)
        {
            int val;
            cin >> val;
            path.push_back(val);
        }
        if(nPath != nVer + 1)
        {
            cout << "NO" << endl;
            continue;
        }
        if(path[0] != path[nPath - 1])
        {
            cout << "NO" << endl;
            continue;
        }
        bool flag = false;
        for(int i = 1; i < nPath; i++)
        {
            if(graph[path[i - 1]][path[i]] == false)
            {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }
        for(int i = 1; i <= nPath; i++)
        {
            isVisit[i] = false;
        }
        for(int i = 1; i < nPath; i++)
        {
            if(isVisit[path[i]] == true)
            {
                cout << "NO" << endl;
                flag = true;
                break;
            }
            isVisit[path[i]] = true;
        }
        if(flag == false)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
