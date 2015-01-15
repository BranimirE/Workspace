#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 102
using namespace std;
int s, t, n, m, f, p[MAX];
bool vis[MAX];
int g[MAX][MAX];
vector<int> ady[MAX];
void augment(int v, int minEdge) {
  if(v == s) {
    f = minEdge;
    return;
  } else if(p[v] != -1) {
    augment(p[v], min(minEdge, g[p[v]][v]));
    g[p[v]][v] -= f;
    g[v][p[v]] += f;
  }
}
int edmondsKarp() {
  int mf = 0;
  while(true) {
    f = 0;
    memset(vis, false, sizeof(vis));
    memset(p  , -1   , sizeof(p));
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      if(u == t)break;
      //for(int v = 1; v <= n; v++){
      for(int i = 0; i < ady[u].size(); i++){
        int v = ady[u][i];
        if(g[u][v] > 0 && !vis[v])
          vis[v] = true, q.push(v), p[v] = u;
      }
    }
    augment(t, 1<<29);
    if(f == 0) break;
    mf += f;
  }
  return mf;
}
int main() {
  freopen("in", "r", stdin);
  int u, v, peso, caso = 1;
  while(scanf("%d", &n) and n) {
    scanf("%d%d%d", &s, &t, &m);
    memset(g, 0, sizeof(g));
    for(int i = 1; i <= n; i++)ady[i].clear();
    while(m--) {
      scanf("%d%d%d", &u, &v, &peso);
      if(g[u][v] == 0)ady[u].push_back(v);
      if(g[v][u] == 0)ady[v].push_back(u);
      g[u][v] += peso;//Si hay varios arcos entre el mismo par de nodos
      g[v][u] += peso;//es lo mismo que sumar el flujo que puede pasar entre ellos
    }
    printf("Network %d\n", caso++);
    printf("The bandwidth is %d.\n\n", edmondsKarp());
  }
  return 0;
}
