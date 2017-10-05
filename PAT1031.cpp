#include <iostream>
using namespace std;
// char buff[100][100];
int main(){
    string input;
    cin >> input;
    int N = input.size();
    int sav = 0;
    for(int n2 = 3; n2 <= N; n2++){
        for(int k = 0; k <= n2; k++){
            if(2 * k + n2 - 2 == N){
                if(k > sav)
                    sav = k;
            }
        }
    }
    int n3 = sav;
    int n1 = n3;
    int n2 = N + 2 - 2 * n1;
    int loc = 0;
    for(int i = 0; i < n1 - 1; i++){
        cout << input[loc];
        for(int j = 0; j < n2 - 2; j++)
            cout << " ";
        cout << input[N - loc - 1] << endl;
        loc++;
    }
    for(int i = 0; i < n2; i++)
        cout << input[loc + i];
    // cout << endl << n1 << " " << n2 << " " << n3 << endl;
    return 0;
}
