#include <cstdio>
#include <algorithm>

using namespace std;
int m[105], t[105];
int main()
{
    int n, lim, e;
    long long int ans, asig;
    while(scanf("%d %d %d", &n, &lim, &e), !(n==0 && lim==0 && e==0)){
        for(int i = 0; i < n; i++)
            scanf("%d", &m[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        sort(m, m + n);
        sort(t, t + n);
        ans = 0;
        for(int i = 0; i < n; i++){
            asig = m[i]+t[n-i-1];
            if(asig > lim)
                ans += ((asig-lim) * e);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
