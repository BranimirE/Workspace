#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>

#define MAX 100005

using namespace std;
vector<int> g[MAX], gt[MAX];
vector<int> S;
int N,M;
int numSCC;
bool vis[MAX];
int scc[MAX];
void dfs(int u, int pass) {
  vis[u] = true;
  vector<int> &ady = ((pass == 1)?g[u]: gt[u]);
  for(int j = 0; j < ady.size(); j++) {
    int v = ady[j];
    if(!vis[v])
      dfs(v, pass);
  }
  if(pass == 1) S.push_back(u);
  else scc[u] = numSCC;
}

int kosaraju() {
  S.clear();
  memset(vis, false, sizeof(vis));
  for(int i = 1; i <= N; i++)//Los nodos estan numerados de 1 - N
    if(!vis[i])
      dfs(i, 1);
  numSCC = 0;
  memset(vis, false, sizeof(vis));
  memset(scc, -1, sizeof(scc));
  for(int i = N-1; i >= 0; i--)
    if(!vis[S[i]]) {
      dfs(S[i], 2);
      numSCC++;
    }
  return numSCC;
}

int main() {
  freopen("in", "r", stdin);
  int t, u, v;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++)g[i].clear(), gt[i].clear();
    while(M--) {
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      gt[v].push_back(u);
    }
    int comp = kosaraju();
    bool en[comp];
    memset(en, false, sizeof(en));
    for(int i = 1; i <= N; i++)
      for(int j = 0; j < g[i].size(); j++) {
        int v = g[i][j];
        if(scc[i] != scc[v])//distintos componentes
          en[scc[v]] = true;
      }
    int ans = 0;
    for(int i = 0; i < comp; i++)
      ans += (!en[i]);
    printf("%d\n", ans);
  }
  return 0;
}
