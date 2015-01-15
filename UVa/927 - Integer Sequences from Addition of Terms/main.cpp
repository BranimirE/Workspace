#include <cstdio>
#include <cmath>
using namespace std;
long long int p[25];
int n, th, i;
long long int d, ans, acu;
long long int evaluar(int i) {
    ans = 0;
    for(int j = 0; j <= n; j++)
        ans += (p[j]*pow(i, j));
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
            scanf("%lld", &p[i]);
        scanf("%lld %d", &d, &th);
        acu = 0;
        for(i = 1; ; i++) {
            if(acu >= th){
                break;
            acu += (d*i);
        }
        printf("%lld\n", evaluar(i-1));
    }
    return 0;
}
