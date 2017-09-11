#include <iostream>
#include <algorithm>
using namespace std;
struct Stu{
    //char name[50];
    string name;
    int height;
};
Stu arr[10500];
int cmp(const void *, const void *);
int main()
{
    int nStu, nRow;
    cin >> nStu >> nRow;
    for(int i = 0; i < nStu; i++)
    {
        cin >> arr[i].name >> arr[i].height;
    }
    qsort(arr, nStu, sizeof(Stu), cmp);
//    for(int i = 0; i < nStu; i++)
//    {
//        cout << arr[i].name << " " << arr[i].height << endl;
//    }
    int eachRow = nStu / nRow;
    int firstLine = eachRow + nStu % eachRow;
    string ans;
    int order = 0;
    for(int i = 0; i < firstLine; i++)
    {
        if(i == 0)
        {
            ans = arr[order].name;
            order++;
            continue;
        }
        if(i % 2 == 1)
        {
            ans = arr[order].name + ' ' + ans;
            order++;
            continue;
        }
        if(i % 2 == 0)
        {
            ans = ans + ' ' + arr[order].name;
            order++;
            continue;
        }
    }
    cout << ans << endl;
    for(int i = 0; i < nRow - 1; i++)
    {
        ans = "";
        for(int j = 0; j < eachRow; j++)
        {
            if(j == 0)
            {
                ans = arr[order].name;
                order++;
                continue;
            }
            if(j % 2 == 1)
            {
                ans = arr[order].name + ' ' + ans;
                order++;
                continue;
            }
            if(j % 2 == 0)
            {
                ans = ans + ' ' + arr[order].name;
                order++;
                continue;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
int cmp(const void * elem1, const void * elem2)
{
    Stu * a = (Stu *) elem1;
    Stu * b = (Stu *) elem2;
    if(a->height != b->height)
    {
        return b->height - a -> height;
    }
    for(int i = 0; i < a->name.length() && i < b->name.length(); i++)
    {
        if(a->name[i] != b->name[i])
            return a->name[i] - b->name[i];
    }
}
