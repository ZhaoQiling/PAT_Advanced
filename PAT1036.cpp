#include <iostream>
using namespace std;
struct Stu{
    Stu(int gr)
        : grade(gr){};
    // Stu(string na, char ge, string id, int gr)
    //     : name(na), gender(ge), ID(id), grade(gr){};
    string name;
    char gender;
    string ID;
    int grade;
};
int main(){
    int nStu;
    cin >> nStu;
    Stu lowestMale(101);
    Stu hightestFeMale(-1);
    for(int i = 0; i < nStu; i++){
        string name;
        char gender;
        string id;
        int score;
        cin >> name >> gender >> id >> score;
        if(gender == 'M' && score < lowestMale.grade){
            lowestMale.name = name;
            lowestMale.gender = gender;
            lowestMale.ID = id;
            lowestMale.grade = score;
        }
        else if(gender == 'F' && score > hightestFeMale.grade){
            hightestFeMale.name = name;
            hightestFeMale.gender = gender;
            hightestFeMale.ID = id;
            hightestFeMale.grade = score;
        }
    }
    if(hightestFeMale.grade != -1)
        cout << hightestFeMale.name << " " << hightestFeMale.ID << endl;
    else
        cout << "Absent" << endl;
    if(lowestMale.grade != 101)
        cout << lowestMale.name << " " << lowestMale.ID << endl;
    else
        cout << "Absent" << endl;
    if(hightestFeMale.grade != -1 && lowestMale.grade != 101)
        cout << hightestFeMale.grade - lowestMale.grade << endl;
    else
        cout << "NA" << endl;
    return 0;
}
