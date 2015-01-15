#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <fstream>

#define MAX 300

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
      for(int i = 0; i < ady[u].size(); i++) {
        int v = ady[u][i];
        if(g[u][v] > 0 && !vis[v])
          vis[v] = true, q.push(v), p[v] = u;
      }
    }
    augment(t, (1<<30));
    if(f == 0) break;
    mf += f;
  }
  return mf;
}
void crearArco(int u, int v, int peso) {
  g[u][v] = peso;// el arco de vuelta peso = 0
  ady[u].push_back(v);
  ady[v].push_back(u);//OJO!!! como estamos recorriendo la lista de adyacencia
}

int entra(int nodo){return nodo;}
int sale(int nodo){return nodo+n;}

int main(){
  freopen("in", "r", stdin);
  while(scanf("%d%d", &n , &m)==2 && !(n==0 && m==0)){
    memset(g, 0, sizeof(g));int lim = sale(n);
    for(int i = 0; i <= lim; i++)ady[i].clear();

    for(int i = 2; i <= n-1; i++){
      int nodo, peso;
      scanf("%d%d", &nodo, &peso);
      crearArco(entra(nodo), sale(nodo), peso);
    }
    while(m--){
      int u, v, peso;
      scanf("%d%d%d", &u, &v, &peso);
      crearArco(sale(u), entra(v), peso);
      crearArco(sale(v), entra(u), peso);
    }
    s =  sale(1);
    t = entra(n);
    printf("%d\n", edmondsKarp());
  }
  return 0;
}
