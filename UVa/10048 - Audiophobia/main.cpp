#include <cstdio>
#include <fstream>

#define MAX 102
#define INF (1<<29)
int mm[MAX][MAX];

using namespace std;
int n, m, q;
int main(){
  freopen("in", "r", stdin);
  int u, v, p;
  int caso = 1;
  while(scanf("%d%d%d", &n, &m, &q) && !(!n && !m && !q)){
    if(caso != 1)puts("");
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        mm[i][j] = (i!=j?INF:0);
    while(m--){
      scanf("%d%d%d", &u, &v, &p);
      mm[u][v] = mm[v][u] = p;
    }
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          mm[i][j] = min(mm[i][j], max(mm[i][k], mm[k][j]));
    printf("Case #%d\n", caso++);
    while(q--){
      scanf("%d%d", &u, &v);
      if(mm[u][v] != INF)
        printf("%d\n", mm[u][v]);
      else
        puts("no path");
    }
  }
  return 0;
}
