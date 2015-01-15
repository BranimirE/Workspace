#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <fstream>
#define MAX 52
#define INF (1<<29)
using namespace std;
int n, m;
int d[MAX][MAX];
map<string, int> id;
int main() {
  freopen("in", "r", stdin);
  string u, v;
  int idd, a, b;
  int caso = 1;
  while(cin >> n >> m && !(!n && !m)) {
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = (i!=j?INF:0);
    id.clear();
    idd = 1;
    while(m--) {
      cin >> u >> v;
      if(!id[u])id[u] = idd++;
      if(!id[v])id[v] = idd++;
      a = id[u], b = id[v];
      d[a][b] = d[b][a] = 1;
    }
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int ans = 0;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        ans = max(ans, d[i][j]);
    printf("Network %d: ", caso++);
    if(ans != INF)
      printf("%d\n", ans);
    else
      puts("DISCONNECTED");
    puts("");
  }
  return 0;
}
