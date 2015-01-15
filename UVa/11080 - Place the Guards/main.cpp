#include <cstdio>
#include <vector>
#include <fstream>
#include <queue>
#include <cstring>

#define MAX 203
#define INF -1
using namespace std;
int n, m, a ,b;
vector<int> g[MAX];
int color[MAX];
int bipartiteCheck(int ini) {
  queue<int> q;
  q.push(ini);
  color[ini] = 0;
  int visitados = 1, negros = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int j = 0; j < g[u].size(); j++) {
      int v = g[u][j];
      if(color[v] == INF) {
        visitados++;
        color[v] = 1 - color[u];
        if(color[v])negros++;
        q.push(v);
      } else if(color[v] == color[u])
        return -1;
    }
  }
  if(visitados == 1) return 1;// si solo es una esquina si o si es necesario un guardia
  return min(negros, visitados - negros);
}

int colorear() {
  memset(color, -1, sizeof(color));
  int ans = 0;
  for(int i = 0; i < n; i++)
    if(color[i] == -1) {
      int tmp = bipartiteCheck(i);
      if(tmp == -1)return -1;
      ans += tmp;
    }
  return ans;
}
int main() {
  //freopen("in", "r", stdin);
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)g[i].clear();

    while(m--) {
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }
    printf("%d\n", colorear());
  }
  return 0;
}
