#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
int nNode;
struct Node{
    vector<int> nodeList;
};
const int arrSize = 10100;
int arr[arrSize];
bool isVis[arrSize];
vector<Node> edge(arrSize);
int getFather(int loc){
    if(arr[loc] == loc)
        return loc;
    loc = getFather(arr[loc]);
    return loc;
}
void merge(int a, int b){
    a = getFather(a);
    b = getFather(b);
    if(a < b)
        arr[b] = a;
    else
        arr[a] = b;
}
void init(){
    for(int i = 0; i <= nNode + 1; i++){
        arr[i] = i;
        isVis[i] = false;
    }
}
int getComponents(){
    int cnt = 0;
    for(int i = 1; i <= nNode; i++){
        if(arr[i] == i)
            cnt++;
    }
    return cnt;
}
set <int> ans;
int maxD = 0;
int dfs(int vertex, int depth){
    if(depth > maxD){
        ans.clear();
        maxD = depth;
    }
    if(depth == maxD)
        ans.insert(vertex);

    for(int i = 0; i < edge[vertex].nodeList.size(); i++){
        if(isVis[edge[vertex].nodeList[i]])
            continue;
        isVis[edge[vertex].nodeList[i]] = true;
        dfs(edge[vertex].nodeList[i], depth + 1);
    }
}
int main(){
    cin >>  nNode;
    if(nNode == 1){
        cout << 1 << endl;
        return 0;
    }
    init();
    for(int i = 0; i < nNode - 1; ++i){
        int a, b;
        cin >> a >> b;
        merge(a, b);
        edge[a].nodeList.push_back(b);
        edge[b].nodeList.push_back(a);
    }
    int cs = getComponents();
    if(cs != 1){
        cout << "Error: " << cs << " components" << endl;
        return 0;
    }

    init();
    isVis[1] = true;
    dfs(1, 0);

    init();
    isVis[*ans.begin()] = true;
    set<int> temp = ans;
    ans.clear();
    dfs(*temp.begin(), 0);

    for(set<int>::iterator it = temp.begin(); it != temp.end(); it++){
        ans.insert(*it);
    }
    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
// 6
// 1 2
// 5 4
// 2 4
// 2 3
// 3 6
