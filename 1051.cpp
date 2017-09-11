#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int sizeOfStack, lenSeq, nSeq;
    cin >> sizeOfStack >> lenSeq >> nSeq;
    for(int k = 0; k < nSeq; k++)
    {
        vector<int> seq(lenSeq + 1);
        stack<int> st;
        bool flag = false;

        for(int i = 1; i <= lenSeq; i++)
            cin >> seq[i];
        int cur = 1;
        for(int i = 1; i <= lenSeq; i++)
        {
            st.push(i);
            if(st.size() > sizeOfStack)
                break;
            while(st.empty() == false && seq[cur] == st.top() )
            {
                //cout << st.top();
                st.pop();
                cur++;
            }
        }
        if(cur == lenSeq + 1)
            flag = true;
        if(flag) cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}
