#include <fstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 105

using namespace std;
int n;
vector<int> g[MAX];
int dist[MAX];
vector<int> ts;
void topsort(int u){
  dist[u] = 1;
  for(int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    if(dist[v] == 0)
      topsort(v);
  }
  ts.push_back(u);
}
int solve(int ini){
  memset(dist, 0, sizeof(dist));
  ts.clear();
  topsort(ini);
  reverse(ts.begin(), ts.end());
  for(int i = 1; i <= n; i++)dist[i] = (1<<29)*(-1);
  dist[ini] = 0;
  for(int i = 0; i < ts.size(); i++){
    int u = ts[i];
    for(int j = 0; j < g[u].size(); j++){
      int v = g[u][j];
      dist[v] = max(dist[v], dist[u] + 1);
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans = max(ans, dist[i]);
  return ans;
}
int main() {
  freopen("in", "r", stdin);
  int ini, fin, u, v, caso = 1;
  while(scanf("%d", &n) and n) {
    for(int i = 1; i <=n; i++)g[i].clear();
    scanf("%d", &ini);
    while(scanf("%d%d", &u, &v) and !(u == 0 && v == 0))
      g[u].push_back(v);
    memset(dist, -1, sizeof(dist));
    int sol = solve(ini);
    fin = ini;
    for(int i = 1; i <= n; i++)
      if(dist[i] == sol) {
        fin = i;
        break;
      }
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",caso, ini, sol, fin);
    caso++;
  }
  return 0;
}
