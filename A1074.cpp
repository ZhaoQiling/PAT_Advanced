#include <iostream>
#include <cstdio>
using namespace std;
int data[100010];
int nextLoc[100010];
int nodeList[100010];
int result[100010];
int main()
{
    int first, nNode, kRe;
    cin >> first >> nNode >> kRe;
    for(int i = 0; i < nNode; i++)
    {
        int temp;
        cin >> temp;
        cin >> data[temp] >> nextLoc[temp];
    }
    int sum = 0;
    while(first != -1)
    {
        nodeList[sum++] = first;
        first = nextLoc[first];
    }

    for(int i = 0; i < sum; i++)
    {
        result[i] = nodeList[i];
    }
    for(int i = 0; i < (sum - sum  % kRe); i++)
    {
        result[i] = nodeList[i / kRe * kRe + kRe - 1 - i % kRe];
    }

    for(int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
    printf("%05d %d -1\n", result[sum - 1], data[result[sum - 1]]);

    return 0;
}
