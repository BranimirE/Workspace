#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

#define MAX 100005
#define MOD 1000000007LL
using namespace std;
typedef long long int Number;
vector<int> g[MAX], gt[MAX];
vector<int> S;
int N, M;
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
  for(int i = 1; i <= N; i++)
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
Number cost[MAX];
int main(){
  int u, v;
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> cost[i];
  cin >> M;
  while(M--){
    cin >> u >> v;
    g[u].push_back(v);
    gt[v].push_back(u);
  }
  int checkposts = kosaraju();
  Number build[checkposts + 5];
  Number ways[checkposts + 5];
  for(int i = 0; i < checkposts; i++){
    build[i] = 1000000050LL;
    ways[i] = 0;
  }
  for(int i = 1; i <= N; i++){
    int comp = scc[i];
    if(cost[i] < build[comp]){
      build[comp] = cost[i];
      ways[comp] = 1;
    }else if(cost[i] == build[comp]){
      ways[comp]++;
    }
  }
  Number totalcost = 0LL;
  Number totalways = 1LL;
  for(int i = 0; i < checkposts; i++){
    totalcost += build[i];
    totalways = (totalways * ways[i]) % MOD;
  }
  cout << totalcost << " " << totalways << endl;
  return 0;
}
