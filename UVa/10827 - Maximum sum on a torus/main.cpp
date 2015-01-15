#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 75
using namespace std;
int v[MAX+MAX+3][MAX+MAX+3];
int main() {

    int n, tmp, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                scanf("%d", &tmp);
                v[i][j] = v[i+n][j] = v[i][j+n] = v[i+n][j+n] = tmp;
            }

        for(int i = 1; i <= n+n; i++)
            for(int j = 1; j <= n+n; j++)
                v[i][j] += (v[i-1][j] + v[i][j-1] - v[i-1][j-1]);

        int ans = -100*MAX*MAX;
        for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)
                for(int k = i; k <= i + n - 1; k++)for(int l = j; l <= j + n - 1; l++)
                        ans = max(ans, v[k][l] - v[i-1][l] - v[k][j-1] + v[i-1][j-1]);
        printf("%d\n", ans);

    }
    return 0;
}
