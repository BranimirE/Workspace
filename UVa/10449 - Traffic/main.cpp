#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>

#define MAX 205
#define oo 1LL<<59

using namespace std;

int n, m;
long long int t[MAX];

vector<pair<int,long long int> > g[MAX];
bool ciclo[MAX];
long long int d[MAX];
bool v[MAX];
void dfs(int i) {
  v[i] = true;
  d[i] = -1;//NO CALCULABLE
  for(int j = 0; j < g[i].size(); j++)
    if(!v[g[i][j].first])
      dfs(g[i][j].first);
}
void bellmanford(int ini) {
  //fill(d + 1, d + 1 + n, oo);
  for(int i = 1; i <= n; i++)d[i] = oo, ciclo[i] = false;
  d[ini] = 0LL;
  for(int i = 0; i < n-1; i++)
    for(int u = 1; u <= n; u++)
      if(d[u] != oo) // Nos aseguramos que ya existe un camino hasta u
        for(int j = 0; j < g[u].size(); j++) {
          pair<int,long long int> v = g[u][j];
          d[v.first] = min(d[v.first], d[u] + v.second);//por que INF + (pesonegativo) es menor que INF
        }
  //verificamos y marcamos todos los nodos que pertenecen a un ciclo negativo
  for(int u = 1; u <= n; u++)
    for(int j = 0; j < g[u].size(); j++) {
      pair<int,int> v = g[u][j];
      if(d[v.first] > d[u] + v.second)
        ciclo[u] = ciclo[v.first] = true;//Ciclo negativo return -1
    }
  //Todos los nodos accesibles desde un nodo con ciclo negativo tambien tienen distancia NO CALCULABLE
  memset(v, false, sizeof(v));
  for(int i = 1; i <= n; i++)
    if(ciclo[i] && !v[i])
      dfs(i);
}
int main() {
  freopen("in", "r", stdin);
  int u, v, caso = 1;

  while(scanf("%d", &n) == 1) {
    for(int i = 1; i <= n; i++) {
      scanf("%lld", &t[i]);
      g[i].clear();
    }
    scanf("%d", &m);
    while(m--) {
      scanf("%d%d", &u, &v);
      long long int tmp = t[v]-t[u];
      g[u].push_back(make_pair(v, tmp * tmp * tmp));
    }
    bellmanford(1);
    scanf("%d", &m);//querys
    printf("Set #%d\n", caso++);
    while(m--) {
      scanf("%d", &v);
      if(d[v] < 3 || d[v] == oo)//No accecible o tiene ciclo negativo
        puts("?");
      else
        printf("%lld\n", d[v]);//Distancia correcta
    }
  }
  return 0;
}
