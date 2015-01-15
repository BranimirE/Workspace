#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 1005
#define MAXW 32
using namespace std;
int dp[MAXN][MAXW];
int v[MAXN], p[MAXN];
int mochila(int i, int libre) {
  if(i < 0)
    return 0;
  int &ans = dp[i][libre];
  if(ans != -1)return ans;
  if(p[i] <= libre)
    ans = max(mochila(i-1, libre), v[i] + mochila(i-1, libre-p[i]));
  else
    ans = mochila(i-1, libre);
  return ans;
}
int main() {
  int t, n, g, lib;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d %d", &v[i], &p[i]);
    int ans = 0;
    memset(dp, -1, sizeof dp);
    scanf("%d", &g);
    while(g--) {
      scanf("%d", &lib);
      ans += mochila(n-1, lib);
    }
    printf("%d\n", ans);
  }
  return 0;
}
