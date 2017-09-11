#include <iostream>
using namespace std;
int arr[10500];
int getF(int val)
{
    if(val == arr[val])
        return val;
    else{
        arr[val] = getF(arr[val]);
        return arr[val];
    }

}
void merge(int a, int b)
{
    int elem1 = getF(a);
    int elem2 = getF(b);
    if(elem1 > elem2)
        arr[elem2] = elem1;
    else
        arr[elem1] = elem2;
}
void init()
{
    for(int i = 1; i <= 10000; i++)
        arr[i] = i;
}
int main()
{
    init();
    int nTree = 0;
    int nBird = 0;
    int nPic;
    cin >> nPic;
    for(int i = 1; i <= nPic; i++)
    {
        int nB;
        cin >> nB;
        int first;
        cin >> first;
        nBird = nBird > first ? nBird : first;
        for(int i = 1; i < nB; i++)
        {
            int val;
            cin >> val;
            nBird = nBird > val ? nBird : val;
            merge(first, val);
        }
    }
    for(int i = 1; i <= nBird; i++)
    {
        arr[i] = getF(arr[i]);
        if(i == arr[i])
        {
            nTree++;
        }
    }
    cout << nTree << " " << nBird << endl;
    int nQuery;
    cin >> nQuery;
    for(int i = 1; i <= nQuery; i++)
    {
        int a, b;
        cin >> a >> b;
        if(arr[a] == arr[b])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }


//    for(int i = 1; i <= nBird; i++)
//        cout << arr[i] << " ";
    return 0;
}
