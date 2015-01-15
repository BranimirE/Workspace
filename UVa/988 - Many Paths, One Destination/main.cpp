#include <cstdio>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
int n;
vector<vector<int> > g;
vector<bool> vis;

void imprimir() {
  for(int u = 0; u < n; u++) {
    int tmp, v;
    printf("%d :", u);
    for(int j = 0; j < g[u].size(); j++){
      v = g[u][j];
      printf("%d, ", v);
    }
    puts("");
  }
}
vector<int> ts;
void dfs(int u){
  vis[u] = true;
  for(int i = 0; i < g[u].size(); i++)
    if(!vis[g[u][i]])
      dfs(g[u][i]);
  ts.push_back(u);
}
void topsort(int ini){
  vector<bool>(n, false).swap(vis);
  ts.clear();
  dfs(ini);
  reverse(ts.begin(), ts.end());
}
vector<int> dp;
int solve(int u){
  int &ans = dp[u];
  if(ans != -1) return ans;
  int tam = g[u].size();
  if(tam == 0)
    return ans = 1;
  ans = 0;
  for(int i = 0; i < tam; i++)
    ans += solve(g[u][i]);
  return ans;
}
int main() {
  freopen("in", "r", stdin);
  bool enter =  false;
  while(scanf("%d", &n) == 1) {
    if(enter) puts("");
    enter = true;
    vector<vector<int> >(n, vector<int>()).swap(g);
    for(int u = 0; u < n; u++) {
      int tmp, v;
      scanf("%d", &tmp);
      while(tmp--) {
        scanf("%d", &v);
        g[u].push_back(v);
      }
    }
    /*
    //SOL 1 (AC)
    vector<int>(n, 0).swap(dp);
    topsort(0);
    dp[0] = 1;
    for(int i = 0; i < ts.size(); i++){
      int u = ts[i];
      for(int j = 0; j < g[u].size(); j++){
        int v = g[u][j];
        dp[v] += dp[u];
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
      if(g[i].size() == 0)
        ans += dp[i];
    printf("%d\n", ans);
    */

    //SOL 2 (AC)
    vector<int>(n, -1).swap(dp);
    printf("%d\n",solve(0));
  }
  return 0;
}
