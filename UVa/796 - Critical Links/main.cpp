#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int idx, tam, ady;
vector<vector<int> > g;
vector<pair<int,int> > ans;
bool b[300][300];
int dfsNumberCounter;
vector<int> num, low, p;
void bridges(int u) {
  low[u] = num[u] = ++dfsNumberCounter;
  for(int j = 0; j < g[u].size(); j++) {
    int v = g[u][j];
    if(num[v] == -1) {
      p[v] = u;
      bridges(v);

      low[u] = min(low[u], low[v]);

      if(low[v] > num[u])
        //b[u][v] = b[v][u] = true;//marcamos como arco bridge
        //ans.push_back(make_pair(min(u, v), max(u, v)));
        if(u < v)
          ans.push_back(make_pair(u, v)));
        else
          ans.push_back(make_pair(v, u)));

    } else if(v != p[u])
      low[u] = min(low[u], num[v]);
  }
}
int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  while(scanf("%d", &n) == 1) {
    if(n) {
      vector<vector<int> >(n, vector<int>()).swap(g);
      for(int i = 0; i < n; i++)
        g[i].clear();
      for(int i = 0; i < n; i++) {
        scanf("%d (%d)", &idx, &tam);
        while(tam--) {
          scanf("%d", &ady);
          g[idx].push_back(ady);
          g[ady].push_back(idx);
        }
      }
      ans.clear();
      dfsNumberCounter = 0;
      vector<int>(n, -1).swap(num);
      vector<int>(n,  0).swap(low);
      vector<int>(n,  0).swap(p);

      //memset(b, 0, sizeof(b));

      for(int i = 0; i < n; i++)
        if(num[i] == -1)
          bridges(i);

      sort(ans.begin(), ans.end());
      tam = ans.size();
      /*
      int tam = 0;
      for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
          if(b[i][j]) {
            ans.push_back(make_pair(i,j));
            tam++;
            b[i][j] = b[j][i] = false;
          }
          */
      printf("%d critical links\n", tam);
      for(int i = 0; i < tam; i++)
        printf("%d - %d\n", ans[i].first, ans[i].second);
      puts("");
    } else
      puts("0 critical links\n");
  }
  return 0;
}
