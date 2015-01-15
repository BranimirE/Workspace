#include <cstdio>
#include <climits>
#include <cstring>
#include <fstream>
using namespace std;

#define MAX 101
#define INF (1<<29)

int n, m;
int d[MAX][MAX];
int main(){
  freopen("in", "r", stdin);
  int t, u, v;
  scanf("%d", &t);
  for(int caso = 1; caso <= t; caso++){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        d[i][j] = (i!=j?INF:0);
    while(m--){
      scanf("%d%d", &u, &v);
      d[u][v] = d[v][u] = 1;
    }
    for(int k = 0; k < n; k++)
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    scanf("%d%d", &u, &v);
    int ans = 0;
    for(int i = 0; i < n; i++)
      ans = max(ans, d[u][i] + d[i][v]);
    printf("Case %d: %d\n", caso, ans);
  }
  return 0;
}
