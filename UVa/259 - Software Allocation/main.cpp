#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstring>
#define MAX 50
#define INF (1<<29)

using namespace std;

int g[MAX][MAX];
int mf, f, s, t;
int p[MAX];

void augment(int v, int minEdge){
  if(v == s){
    f = minEdge;
    return;
  }else if(p[v] != -1){
    augment(p[v], min(minEdge, g[p[v]][v]));
    g[p[v]][v] -= f;
    g[v][p[v]] += f;
  }
}
int dist[MAX];

int edmondsKarp(){
  mf = 0;
  while(true){
    f = 0;
    vector<int> dist(MAX, INF);
    dist[s] = 0;
    queue<int> q; q.push(s);
    memset(p, -1, sizeof(p));
    while(!q.empty()){
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int v = 0; v < MAX; v++)
        if(g[u][v] > 0 && dist[v] == INF)
          dist[v] = dist[u] + 1, q.push(v), p[v] = u;
    }
    augment(t, INF);
    if(f == 0) break;
    mf += f;
  }
  return mf;
}

/*s = 0; t = 1; A - Z = 2 - 27; 0 - 9 = 28 - 37 */

int procesar(string &cad){
  stringstream ss(cad);
  string app;
  ss >> app;
  int nodo = app[0] - 'A' + 2;
  int peso = app[1] - '0';
  g[s][nodo] = peso;
  ss >> app;
  for(int i = 0; i < app.size()-1; i++){
    int ady = app[i] - '0' + 28;
    g[nodo][ady] = INF;
    g[ady][t] = 1;
  }
  return peso;
}

int main(){
  freopen("in", "r", stdin);
  string cad;
  s = 0; t = 1;
  while(getline(cin, cad)){
    memset(g, 0, sizeof(g));
    int total = procesar(cad); // Total de peticiones de apps
    while(getline(cin, cad) && !cad.empty())
      total += procesar(cad);
    int flujo = edmondsKarp();
    if(flujo == total){
      for(int i = 28; i <= 37; i++){
        char ans = 0;
        for(char j = 'A'; j <= 'Z'; j++){
          int ady = j - 'A' + 2;
          if(g[i][ady] == 1){
            ans = j;
            break;
          }
        }
        if(ans)
          putchar(ans);
        else
          putchar('_');
      }
    }else
      putchar('!');
    puts("");
  }
  return 0;
}
