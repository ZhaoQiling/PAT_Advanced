#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<long long> arr;
// bool cmp(const int& a, const int& b){
//     return a < b;
// }
int main(){
    int nA;
    // cin >> nA;
    scanf("%lld", &nA);
    for(int i = 0; i < nA; i++){
        long long val;
        // cin >> val;
        scanf("%lld", &val);
        arr.push_back(val);
    }
    int nB;
    cin >> nB;
    for(int i = 0; i < nB; i++){
        long long val;
        // cin >> val;
        scanf("%lld", &val);
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    printf("%lld", arr[(arr.size() - 1) / 2]);
    return 0;
}
