#include <cstdio>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 102
using namespace std;
int n,m;
vector<int> g[MAX];
int en[MAX]; // entrantes
queue<int> cola;
void buscar() {
  for(int i = 1; i <= n; i++)
    if(en[i] == 0) {
      en[i] = -1;
      cola.push(i);
    }
}
int main() {
  freopen("in", "r", stdin);
  while(scanf("%d%d", &n, &m) and !(!n and !m)) {
    for(int i = 1; i <= n; i++)g[i].clear();
    int a, b;
    memset(en, 0, sizeof(en));
    while(m--) {
      scanf("%d%d", &a,&b);
      g[a].push_back(b);
      en[b]++;//adicionamos arco entrante
    }
    vector<int> ts;
    buscar();

    while(!cola.empty()) {
      int act = cola.front();
      cola.pop();
      ts.push_back(act);
      for(int i = 0; i < g[act].size(); i++) {
        int ady = g[act][i];
        en[ady]--;// quitamos el arco entrante
        if(en[ady] == 0)//si ya no tiene arcos entrantes
          cola.push(ady);
      }
    }
    //if ts.size() != n => Grafo Invalido
    for(int i = 0; i < n; i++) {
      if(i) printf(" ");
      printf("%d", ts[i]);
    }
    puts("");
  }
  return 0;
}
