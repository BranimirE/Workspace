#include <cstdio>

using namespace std;
int n;
long long int v[20];

int main()
{
    bool space = false;
    int a, b,c,d,e,f;
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++)
            scanf("%lld", &v[i]);
        if(space)
            puts("");
        space = true;
        for(a = 0; a <= n - 6; a++)
            for(b = a + 1; b <= n - 5; b++)
                for(c = b + 1; c <= n - 4; c++)
                    for(d = c + 1; d <= n - 3; d++)
                        for(e = d + 1; e <= n - 2; e++)
                            for(f = e + 1; f <= n - 1; f++)
                                printf("%lld %lld %lld %lld %lld %lld\n", v[a], v[b], v[c], v[d], v[e], v[f]);
    }
    return 0;
}
