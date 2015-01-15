#include <cstdio>

using namespace std;
int v[25];
int main()
{
    int t, obj, n, tmp;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &obj, &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        bool ans = false;
        for(int mask = 0; mask < (1<<n) && !ans; mask++){
            tmp = 0;
            for(int i = 0; i < n; i++)
                if(mask & (1<<i))
                    tmp += v[i];
            if(tmp == obj)
                ans = true;
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}
