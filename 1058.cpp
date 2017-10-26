#include <cstdio>
using namespace std;
int main(){
    long long g1, s1, k1;
    scanf("%lld.%lld.%lld", &g1, &s1, &k1);
    long long g2, s2, k2;
    scanf("%lld.%lld.%lld", &g2, &s2, &k2);

    k1 += 17 * 29 * g1 + s1 * 29;
    k2 += 17 * 29 * g2 + s2 * 29;
    k1 += k2;

    printf("%lld.%lld.%lld", k1 / (17 * 29), k1 / 29 % 17, k1 % 29);
    return 0;
}
