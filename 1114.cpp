#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Peo{
    int boss;
    int M_estate;
    int Aera;
};
struct Family{
    int bossID;
    int nMember;
    double sets;
    double area;
};
Peo arr[10500];
Family fam[10500];
bool isArr[10500];
int getBoss(int id)
{
    if(id == arr[id].boss)
        return id;
    else{
        arr[id].boss = getBoss(arr[id].boss);
        return arr[id].boss;
    }
}
void merge(int a, int b)
{
    a = getBoss(a);
    b = getBoss(b);
    if(a < b)
        arr[b].boss = a;
    else
        arr[a].boss = b;
}
int cmp(const void * elem1, const void * elem2)
{
    Family * a = (Family *) elem1;
    Family * b = (Family *) elem2;
    if(a->area != b->area)
    {
        if(a->area < b->area)
            return 1;
        else
            return -1;
    }
    return a->bossID - b->bossID;

}
int main()
{
    int nPeo;
    cin >> nPeo;
    for(int i = 0; i <= 9999; i++)
    {
        arr[i].boss = i;
    }
    for(int j = 1; j <= nPeo; j++)
    {
        int id;
        cin >> id;
        isArr[id] = true;
        int father, mother;
        cin >> father >> mother;
        if(father != -1)
        {
            isArr[father] = true;
            merge(id, father);
        }
        if(mother != -1)
        {
            isArr[mother] = true;
            merge(id, mother);
        }
        int nChild;
        cin >> nChild;
        for(int i = 1; i <= nChild; i++)
        {
            int child;
            cin >> child;
            isArr[child] = true;
            merge(id, child);
        }
        cin >> arr[id].M_estate >> arr[id].Aera;
    }
    int total = 0;
    for(int i = 0; i <= 9999; i++ )
    {
        arr[i].boss = getBoss(i);
        if(i == arr[i].boss && isArr[i] == true)
        {
            total++;
        }
    }
    cout << total << endl;
    int order = 0;
    for(int i = 0; i <= 9999; i++)
    {
        if(i == arr[i].boss && isArr[i] == true)
        {
            int member = 0;
            double estate = 0;
            double area = 0;
            for(int j = 0; j <= 9999; j++)
            {
                if(arr[j].boss == i)
                {
                    member++;
                    area += arr[j].Aera;
                    estate += arr[j].M_estate;
                }
            }
            fam[order].bossID = i;
            fam[order].nMember = member;
            fam[order].area = area / member;
            fam[order].sets = estate / member;
            order++;
            if(order == total)
                break;
        }
    }
    qsort(fam, total, sizeof(Family), cmp);
    for(int i = 0; i < total; i++)
    {
        cout << setfill('0') << setw(4) << fam[i].bossID;
        cout << " " << fam[i].nMember << " " << fixed << setprecision(3) << fam[i].sets << " " << fam[i].area << endl;
    }
    return 0;
}
