#include <iostream>
#include <vector>
using namespace std;
int graph[550][550];
const int INF = 9999999;
int dis[550];
bool isVisit[550];
int main()
{
    int nCity, nRoad, startC, endC;
    cin >> nCity >> nRoad >> startC >> endC;
    vector<int> team(nCity);
    for(int i = 0; i < nCity; i++)
        cin >> team[i];
    for(int i = 0; i < nCity; i++)
    {
        for(int j = 0; j < nCity; j++)
        {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    for(int i = 0; i < nRoad; i++)
    {
        int s, e, len;
        cin >> s >> e >> len;
        if(len < graph[s][e] || graph[s][e] == 0)
        {
            graph[s][e] = len;
            graph[e][s] = len;
        }
    }
    for(int i = 0; i < nRoad; i++)
    {
        dis[i] = graph[startC][i];
    }
    isVisit[startC] = true;
    for(int i = 1; i < nCity; i++)
    {
        int minDis = INF;
        int u, v;
        for(int j = 0; j < nCity; j++)
        {
            if(dis[j] < minDis && isVisit[j] == false)
            {
                minDis = dis[j];
                u = j;
            }
        }
        isVisit[u] = true;
        for(v = 0; v < nCity; v++)
        {
            if(dis[u] + graph[u][v] < dis[v])
                dis[v] = dis[u] + graph[u][v];
        }
        cout << dis[endC];
    }
    return 0;
}
