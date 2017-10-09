#include <cstdio>
#include <vector>
#include <set>
using namespace std;
set<int> crosslist[26 * 26 * 26 * 10 + 100];
int s2i(char* s){
    return (s[0] - 'A') * 26 * 26 * 10
        + (s[1] - 'A') * 26 * 10
        + (s[2] - 'A') *  10
        + (s[3] - '0');
}
int main(){
    int nQuery, nCourse;
    scanf("%d%d", &nQuery, &nCourse);
    for(int i = 0; i < nCourse; i++){
        int numCour, nStu;
        scanf("%d%d", &numCour, &nStu);
        for(int j = 0; j < nStu; j++){
            char name[5];
            scanf("%s", name);
            int id = s2i(name);
            crosslist[id].insert(numCour);
        }
    }
    for(int i = 0; i < nQuery; i++){
        char name[5];
        scanf("%s", name);
        printf("%s ", name);
        int id = s2i(name);
        printf("%d", crosslist[id].size());
        for(auto it = crosslist[id].begin(); it != crosslist[id].end(); ++it){
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}
