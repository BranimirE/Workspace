#include <cstdio>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>

#define DFS_WHITE -1
#define MAX 100005

using namespace std;

int n, m, ans;
vector<int> S, visited, dfs_low, dfs_num;
vector<int> g[MAX];
int scc[MAX];
bool en[MAX];
int numSCC, dfsNumberCounter;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  //printf("visita  : %d\n", u);

  for (int j = 0; j < g[u].size(); j++) {
    int v = g[u][j];
    if (dfs_num[v] == DFS_WHITE) {
      //printf("llama a %d\n", v);
      tarjanSCC(v);
    }

    if (visited[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {

    //printf("SCC %d:", ++numSCC);
    while (1) {
      int v = S.back();
      S.pop_back();
      scc[v] = numSCC;
      visited[v] = 0;
      if (u == v) break;
    }
    numSCC++;
  }
}
int main() {
  freopen("in", "r", stdin);
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)g[i].clear();
    memset(en, 0, sizeof(en));
    while(m--) {
      int a, b;
      scanf("%d%d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
      en[b] = true;
    }
    ans = 0;

    /*
    for(int i = 1 ; i <= n; i++){
      printf("%d :", i) ;
      for(int j = 0; j < g[i].size(); j++)
        printf(" %d", g[i][j]);
      puts("");
    }
    */
    vector<int>(n+1,DFS_WHITE).swap(dfs_num);
    vector<int>(n+1, 0).swap(dfs_low);
    vector<int>(n+1, 0).swap(visited);
    S.clear();

    dfsNumberCounter = numSCC = 0;

    for (int i = 1; i <= n; i++)
      if (dfs_num[i] == DFS_WHITE)
        tarjanSCC(i);
    bool entra[numSCC];
    memset(entra, false, sizeof(entra));
    for(int u = 1; u <= n; u++)
      for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(scc[u] != scc[v])
          entra[scc[v]] = true;
      }

    //for(int i = 1; i <= n; i++)
    //printf("%d: num = %d, low = %d\n", i, dfs_num[i], dfs_low[i]);
    //printf("%d\n", numSCC);
    printf("%d\n", count(entra, entra + numSCC, false));

  }
  return 0;
}
