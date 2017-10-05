#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct Cos
{
    int arriTime;
    int procTime;
};
bool cmp(Cos a, Cos b){
    return a.arriTime < b.arriTime;
}
int main(){
    int nCos, nWin;
    cin >> nCos >> nWin;
    Cos* arr = new Cos[nCos + 1];
    for(int i = 0; i < nCos; ++i){
        int h, s, m, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        arr[i].arriTime = s + m * 60 + h * 60 * 60;
        arr[i].procTime = p * 60;
    }
    sort(arr, arr + nCos, cmp);
//    for(int i = 0; i < nCos; ++i){
//        cout << arr[i].arriTime << " " << arr[i].procTime << endl;
//    }
//    cout << endl;
    priority_queue<int, vector<int>, greater<int> > que;
    int totalPro = 0;
    int totalTime = 0;
    for(int i = 0; i < nCos; ++i){
        if(arr[i].arriTime > 17 * 3600)
            break;
        if(que.size() < nWin){
            if(arr[i].arriTime < 8 * 3600){
                totalTime += 8 * 3600 - arr[i].arriTime;
                arr[i].arriTime = 8 * 3600;
                que.push(8 * 3600 + arr[i].procTime);
            }
            else{
                que.push(arr[i].arriTime + arr[i].procTime);
            }
        }
        else{
            int temp = que.top();
            que.pop();
            if(temp >= arr[i].arriTime){
                totalTime += temp - arr[i].arriTime;
                que.push(temp + arr[i].procTime);
            }
            else{
                que.push(arr[i].arriTime + arr[i].procTime);
            }
        }
        ++totalPro;
    }
//    cout << totalTime << " " << totalPro << endl;
    printf("%.1f", totalTime / 60.0 / totalPro);

    return 0;
}
