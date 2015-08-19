#include <bits/stdc++.h>

using namespace std;

//struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
const int MAXN = 300010;
const int inf = 1 << 28;
char buff[4000020], tmpstr[60];
char *token;

map<string, int> idParada, idLinea;
int nparadas, nlineas;
string nom_ini, nom_fin;
vector<int> paradas[100010];//paradas de la "linea X"   paradas[X]
vector<int> lineas[MAXN];//lineas que pasan por la "parada X" lineas[X]
int S, T;
int n;
void read() {
  getchar();//inician con una linea vacia
  idParada.clear();
  idLinea.clear();
  nparadas = 0;
  nlineas = 0;
  
  //stops
  scanf("Stops: %[^\n]", buff);
  getchar();
  //cout << buff << endl;
  token = strtok(buff, ", ");
  while (token != NULL) {
    idParada[token] = nparadas++;
    token = strtok(NULL, ", ");
  }

  //lines
  scanf("Lines: %[^\n]", buff);
  getchar();
  token = strtok(buff, ", ");
  while (token != NULL) {
    idLinea[token] = nlineas++;
    token = strtok(NULL, ", ");
  }
  forn (i, nparadas)
    lineas[i].clear();

  forn (i, nlineas) {
    scanf("%s route: %[^\n]", tmpstr, buff);
    getchar();
    int id_linea = idLinea[tmpstr];    
    paradas[id_linea].clear();
    token = strtok(buff, ", ");
    while (token != NULL) {
      int id_parada = idParada[token];
      paradas[id_linea].pb(id_parada);
      lineas[id_parada].pb(id_linea);
      token = strtok(NULL, ", ");
    }
  }
  scanf("Johny lives at %s", tmpstr);
  getchar();
  nom_ini = string(tmpstr);
  S = idParada[nom_ini];
  scanf("Michelle lives at %s", tmpstr);
  getchar();
  nom_fin = string(tmpstr);
  T = idParada[nom_fin];
  n = nparadas;
}

int max_arcos_T, min_cambios_T;
bool vis[100010];//dist[lineaX] distancia a la linea con id lineaX
int max_paradas[MAXN];
void solve() {
  
  /*forn (id_linea, nlineas) {
    cout << "Linea = " << id_linea << " :";
    for (int parada: paradas[id_linea])
      cout << " " << parada;
    cout << endl;
  }
  forn (id_parada, nparadas) {
    cout << "Parada = " << id_parada << " :";
    for (int linea: lineas[id_parada])
      cout << " " << linea;
    cout << endl;
  }
  cout << endl;*/

  memset(vis, false, sizeof(vis));
  memset(max_paradas, -1, sizeof(max_paradas));
  vector<int> q;
  q.pb(S);
  max_paradas[S] = 0;
  
  for (int d = 0; ; d++) {
    vector<int> cambios;
    for (int parada: q) {
      if (parada == T) {
        max_arcos_T = max_paradas[T];
        min_cambios_T = d;
        return;
      }
      for (int linea: lineas[parada])
        cambios.pb(linea);
    }

    map<int, int> actualizaciones;
    for (int linea: cambios) {
      if (!vis[linea]) {
        vis[linea] = true;
        //Barridos
        int lejos = INT_MIN;
        for (int i = 0; i < sz(paradas[linea]); i++) {
          int parada = paradas[linea][i];
          if (max_paradas[parada] == -1)
            actualizaciones[parada] = max(actualizaciones[parada], lejos);
          else
            lejos = max(lejos, max_paradas[parada]);
          lejos++;
        }
        lejos = INT_MIN;
        for (int i = sz(paradas[linea]) - 1; i >= 0; i--) {
          int parada = paradas[linea][i];
          if (max_paradas[parada] == -1)
            actualizaciones[parada] = max(actualizaciones[parada], lejos);
          else
            lejos = max(lejos, max_paradas[parada]);
          lejos++;
        }
      }
    }
    q.clear();
    for (auto e: actualizaciones) {
      int parada = e.first;
      int maxi_paradas = e.second;
      max_paradas[parada] = maxi_paradas;
      q.pb(parada);
    }
  }
}
void print() {
  printf("optimal travel from %s to %s:", nom_ini.c_str(), nom_fin.c_str() );
 
  printf(" %d ", min_cambios_T);
  if (min_cambios_T == 1)
    printf("line,");
  else
    printf("lines,");

  printf(" %d ", max_arcos_T);
  if (max_arcos_T == 1)
    printf("minute");
  else
    printf("minutes");
  
  printf("\n");
}
int main() { 
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    read();
    solve();
    print();
  }
  return 0;
}
