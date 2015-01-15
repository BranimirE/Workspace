#include <cstdio>
#include <algorithm>

using namespace std;
int v[10005];
int n, m, mid, ans;
int main() {
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        scanf("%d", &m);
        sort(v, v + n);
        mid = m >> 1;
        for(int i = 0; i < n && v[i] <= mid; i++)
            if(binary_search(v + i + 1, v + n, m - v[i]))
                ans = v[i];
        printf("Peter should buy books whose prices are %d and %d.\n\n", ans, m-ans);
    }
    return 0;
}
