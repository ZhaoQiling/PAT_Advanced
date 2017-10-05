#include <iostream>
#include <stack>
using namespace std;
const int arrSize = 510;
const int INF = 9999999;

int dist[arrSize][arrSize];
int cost[arrSize][arrSize];
int path[arrSize];
int disCost[arrSize];
int disDist[arrSize];
bool isVis[arrSize];
int nVertex, nEdge, srcCity, tarCity;
void init(){
    for(int i = 0; i < nVertex; i++){
        path[i] = -1;
        disCost[i] = INF;
        disDist[i] = INF;
        isVis[i] = false;
        for(int j = 0; j < nVertex; j++){
            dist[i][j] = cost[i][j] = INF;
            if(i == j){
                dist[i][i] = cost[i][i] = 0;
            }
        }
    }
}
int main(){
    cin >> nVertex >> nEdge >> srcCity >> tarCity;
    init();
    for(int i = 0; i < nEdge; i++){
        int a, b;
        cin >> a >> b;
        cin >> dist[a][b] >> cost[a][b];
        dist[b][a] = dist[a][b];
        cost[b][a] = cost[a][b];
    }
    for(int i = 0; i < nVertex; i++){
        disDist[i] = dist[srcCity][i];
        disCost[i] = cost[srcCity][i];
    }

    isVis[srcCity] = true;
    for(int i = 0; i < nVertex - 1; ++i){
        int u;
        int minV = INF;
        for(int j = 0; j < nVertex; j++){
            if(isVis[j])
                continue;
            if(disDist[j] < minV){
                minV = disDist[j];
                u = j;
            }
        }
        isVis[u] = true;
        for(int v = 0; v < nVertex; v++){
            if(disDist[u] + dist[u][v] < disDist[v]){
                disDist[v] = disDist[u] + dist[u][v];
                disCost[v] = disCost[u] + cost[u][v];
                path[v] = u;
            }
            else if(disDist[u] + dist[u][v] == disDist[v]){
                if(disCost[u] + cost[u][v] < disCost[v]){
                    disCost[v] = disCost[u] + cost[u][v];
                    path[v] = u;
                }
            }
        }
    }

    stack<int> sav;
    int p = tarCity;
    while(p != -1){
        sav.push(p);
        p = path[p];
    }
    sav.push(srcCity);
    while(!sav.empty()){
        cout << sav.top() << " ";
        sav.pop();
    }
    cout << disDist[tarCity] << " " << disCost[tarCity];
    return 0;
}
