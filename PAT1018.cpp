#include <iostream>
using namespace std;
int vertex[110][110];
int main(){
    int capMax, nSta, proSta, nEdge;
    cin >> capMax >> nSta >> proSta >> nEdge;

    int* cap = new int [nSta + 1];
    for(int i = 1; i <= nSta; ++i)
        cin >> cap[i];
    for(int i = 0; i < nEdge; ++i){
        cin >> a >> b >> c;
        vertex[a][b] = vertex[b][a] = c;
    }

    
    return 0;
}
