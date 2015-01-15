#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>

#define MAX 2005

using namespace std;
vector<int> g[MAX], gt[MAX];
vector<int> S;//para el topsort
int N,M;// nodos, edges
int numSCC;
bool vis[MAX];
int scc[MAX];// Para asignar scc correspondiente
void dfs(int u, int pass) {
  vis[u] = true;
  vector<int> &ady = ((pass == 1)?g[u]: gt[u]);
  for(int j = 0; j < ady.size(); j++) {
    int v = ady[j];
    if(!vis[v])
      dfs(v, pass);
  }
  if(pass == 1) S.push_back(u);//adicionamos al topsort
  else scc[u] = numSCC; // asignamos a que SCC pertenece el nodo
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
int main(){
  //freopen("in", "r", stdin);
  int u, v, sent;
  while(scanf("%d%d", &N, &M) and !(!N and !M)){
    for(int i = 1; i <= N; i++)g[i].clear(), gt[i].clear();
    while(M--){
      scanf("%d%d%d", &u, &v, &sent);
      if(sent == 1){//un solo sentido
        g[u].push_back(v);
        gt[v].push_back(u);
      }else{//Doble sentido
        g[u].push_back(v);g[v].push_back(u);
        gt[v].push_back(u);gt[u].push_back(v);
      }
    }
    printf("%d\n", kosaraju()==1);
  }
  return 0;
}
