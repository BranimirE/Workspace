#include <cstdio>
#include <set>
#include <vector>
#include <fstream>
#include <climits>

#define MAX 1005

#define oo 1<<28

using namespace std;
int n, m, precio[MAX];
int d[MAX][102];
vector<pair<int,int> > g[MAX];
pair<int,int>  tmp;
int dist, gas, act, ady, peso, capacidad;
int main() {
  //freopen("in", "r", stdin);
  int u, v, p;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &precio[i]);

  while(m--) {
    scanf("%d%d%d", &u, &v, &p);
    g[u].push_back(make_pair(v, p));
    g[v].push_back(make_pair(u, p));
  }
  /*
    puts("Grafo :");
    for(int i = 0; i < n; i++){
      printf("%d :", i);
      for(int j = 0; j < g[i].size(); j++)
        printf(" %d(%d)", g[i][j].first, g[i][j].second);
      puts("");
    }
    puts("");
  */
  scanf("%d", &m);
  while(m--) {
    scanf("%d%d%d", &capacidad, &u, &v );
    set<pair<int, pair<int,int> > > cola;
    for(int i = 0; i < n; i++)
      for(int j = 0; j <= 100; j++)
        d[i][j] = oo;
    cola.insert(make_pair(0, make_pair(u, 0)));
    d[u][0] = 0;
    while(!cola.empty()) {
      tmp = (*(cola.begin())).second;
      cola.erase(cola.begin());
      act = tmp.first;
      gas = tmp.second;
      if(act == v)break;//Ya llegamos y estamos seguros que es la menor distancia a esta ubicacion
      //printf("ACTUAL : %d (%d)\n", act, gas);
      //No cargamos nada en la ubicacion actual actual y seguimos con los vecinos
      for(int i = 0; i < g[act].size(); i++) {
        ady = g[act][i].first;
        peso = g[act][i].second;
        if(gas >= peso && d[act][gas] + 0 < d[ady][gas - peso]) {
          d[ady][gas - peso] = d[act][gas] + 0;
          cola.insert(make_pair(d[ady][gas-peso], make_pair(ady, gas-peso)));
          //printf(" a - inserta %d (%d)\n", ady, gas-peso);
        }
      }
      //Cargamos una unidad de gasolina en la ubicacion actual
      if(gas + 1 <= capacidad && d[act][gas] + precio[act] < d[act][gas + 1]) {
        d[act][gas + 1] =  d[act][gas] + precio[act];
        cola.insert(make_pair(d[act][gas] + precio[act], make_pair(act, gas + 1)));
        //printf(" b - inserta %d (%d)\n", act, gas + 1);
      }
    }
    /*
        printf("%s", "Cap");
        for(int i = 0; i <= capacidad ; i++)
          printf("%10d", i);
        puts("");
        for(int i = 0; i < n; i++){
          printf("%d :", i);
          for(int j = 0; j <= capacidad; j++)
            printf("%10d", d[i][j]);
          puts("");
        }
    */
    int ans = INT_MAX;

    for(int tank = 0; tank <= capacidad; tank++)
      ans = min(ans, d[v][tank]);
    if(ans != oo)
      printf("%d\n", ans);
    else
      puts("impossible");
  }
  return 0;
}
