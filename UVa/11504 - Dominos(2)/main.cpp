#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100005
using namespace std;
int n, m;
vector<int> g[MAX], gt[MAX];
vector<int> ts;
bool vis[MAX];
bool entra[MAX];
int scc[MAX];
int numSCC;
void dfs(int u, int pass){
  vis[u] = true;
  vector<int> &ady = (pass==1)?g[u]:gt[u];
  for(int i = 0; i < ady.size(); i++){
    int v = ady[i];
    if(vis[v] == false)
      dfs(u, pass);
  }
  if(pass == 1)ts.push_back(u);
  else scc[u] = numSCC;
}
int main(){
  int cases;
  cin >> cases;
  while(cases--){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
      g[i].clear();
      gt[i].clear();
    }
      
    while(m--){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      gt[v].push_back(u);
    }
    ts.clear();
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++)
      if(!vis[i])
        dfs(i, 1);
    memset(vis, false, sizeof(vis));
    numSCC = 0;
    for(int i = n - 1; i >= 0; i--){
      int cur = ts[i];
      if(!vis[cur]){
        dfs(cur, 2);
        numSCC++;
      }
    }
    memset(entra, false, sizeof(entra));
    for(int i = 1; i <= n; i++)
      for(int j = 0; j < g[i].size(); j++){
        int u = i, v = g[i][j];
        u = scc[u], v = scc[v];
        if(u != v)
          entra[v] = true;
      }
    int ans = 0;
    for(int i = 0; i < numSCC; i++)
      if(entra[i] == false)
        ans++;
    cout << ans << endl;
  }
  return 0;
}
