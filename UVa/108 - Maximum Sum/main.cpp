#include <cstdio>
#include <algorithm>
#define MAX 103
using namespace std;
int v[MAX][MAX] = {0};
int main() {
    int n, tmp;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            scanf("%d", &v[i][j]);
            v[i][j] += (v[i-1][j] + v[i][j-1] - v[i-1][j-1]);
        }
    int ans = -127*100*100;
    for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)
    for(int k = i; k <= n; k++)for(int l = j; l <= n; l++)
        ans = max(ans, v[k][l] - v[i-1][l] - v[k][j-1] + v[i-1][j-1]);
    printf("%d\n", ans);
    return 0;
}
