#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>

#define MAX 13

using namespace std;

pair<int,int> v[MAX];
int d[MAX][MAX];
int p[MAX];
int n;
int main() {
  //freopen("in", "r", stdin);
  int t, x, y;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &x, &y);
    scanf("%d%d", &v[0].first, &v[0].second);
    scanf("%d", &n);
    p[0] = 0;
    for(int i = 1; i <= n; i++) {
      p[i] = i;
      scanf("%d%d", &v[i].first, &v[i].second);
    }
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= n; j++)
        d[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
    int ans = 1<<30;
    do {
      int tmp = 0;
      for(int i = 1; i <= n; i++)
        tmp += d[p[i-1]][p[i]];
      tmp += d[p[n]][0];
      ans = min(ans, tmp);
    } while(next_permutation(p+1, p + 1 + n));
    printf("The shortest path has length %d\n", ans);
  }
  return 0;
}
