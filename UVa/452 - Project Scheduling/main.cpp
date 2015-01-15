#include <cstdio>
#include <cstring>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
#define MAX 30

vector<int> g[MAX];
int t[MAX];
int dp[MAX];
char buff[1000], cad[30];
int solve(int u) {
  if(dp[u] != -1) return dp[u];
  int ans = 0;
  for(int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    ans = max(ans, t[v] + solve(v));
  }
  return (dp[u] = ans);
}
int main() {
  freopen("in", "r", stdin);
  int test;
  char a;
  int tmp, u, v, tam;
  scanf("%d", &test);
  getchar();
  getchar();
  while(test--) {
    for(int i = 0; i < MAX; i++) g[i].clear();
    memset(t, -1, sizeof(t));
    while(gets(buff) && strlen(buff)) {
      cad[0] = '\0';
      sscanf(buff, "%c %d %s", &a, &tmp, cad);
      v = a - 'A';
      t[v] = tmp;
      tam = strlen(cad);
      for(int i = 0; i < tam; i++) {
        u = cad[i] - 'A';
        g[u].push_back(v);
      }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i <= 26; i++)
      if(t[i] != -1)
        ans = max(ans, t[i] + solve(i));
    printf("%d\n", ans);
    if(test)puts("");
  }
  return 0;
}
