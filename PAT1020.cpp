#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
    Node *leftChild, *rightChild;
    int data;
    Node(int d, Node* l, Node* r)
        : data(d), leftChild(l), rightChild(r){};
};
vector<int> postOrder;
vector<int> inOrder;
Node* constructTree(int postLoc, int inLoc, int length){
    // cout << length << endl;
    if(length <= 0)
        return NULL;
    Node* temp = new Node(postOrder[postLoc + length - 1], NULL, NULL);

    int loc = inLoc;
    for(; loc < inLoc + length
            && inOrder[loc] != postOrder[postLoc + length - 1]; loc++);

    temp->leftChild = constructTree(postLoc, inLoc, loc - inLoc);
    temp->rightChild = constructTree(postLoc + loc - inLoc, loc + 1, inLoc + length - loc - 1);

    return temp;
}
int nNode;
void prTree(Node* root){
    queue<Node*> que;
    que.push(root);
    int cnt = 0;
    while(!que.empty()){
        cout << que.front()-> data;
        cnt++;
        if(cnt != nNode)
            cout << " ";
        if(que.front()->leftChild != NULL)
            que.push(que.front()->leftChild);

        if(que.front()->rightChild != NULL)
            que.push(que.front()->rightChild);

        que.pop();
    }
}
int main(){
    cin >> nNode;
    for(int i = 0; i < nNode; ++i){
        int data;
        cin >> data;
        postOrder.push_back(data);
    }
    for(int i = 0; i < nNode; ++i){
        int data;
        cin >> data;
        inOrder.push_back(data);
    }
    // for(int i = 0; i < postOrder.size(); i++){
    //     cout << postOrder[i];
    // }
    // cout << endl;
    // for(int i = 0; i < inOrder.size(); i++){
    //     cout << inOrder[i];
    // }
    Node* root = constructTree(0, 0, nNode);
    prTree(root);
    return 0;
}
