#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> preOrder;
vector<int> inOrder;
vector<int> postOrder;
void postorder(int root, int start, int end)
{
    if(start > end) return;
    int i = start;
    while(i < end && inOrder[i] != preOrder[root]) i++;
    postorder(root + 1, start, i - 1);
    postorder(root + i - start + 1, i + 1, end);
    postOrder.push_back(preOrder[root]);
}
int main()
{
    int nNode;
    cin >> nNode;
    stack<int> oper;
    string op;
    while(cin >> op)
    {
        if(op == "Push")
        {
            int val;
            cin >> val;
            oper.push(val);
            preOrder.push_back(val);
        }
        else if(op == "Pop")
        {
            inOrder.push_back(oper.top());
            oper.pop();
        }
    }
    postorder(0, 0, nNode - 1);
//    for(int i = 0; i < preOrder.size(); i++)
//    {
//        cout << preOrder[i] << " ";
//    }
//    cout << endl;
//    for(int i = 0; i < inOrder.size(); i++)
//    {
//        cout << inOrder[i] << " ";
//    }
    cout << postOrder[0];
    for(int i = 1; i < postOrder.size(); i++)
        cout << " " << postOrder[i];
    return 0;
}
