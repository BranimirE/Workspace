#include <bits/stdc++.h>
#define MAX 205
using namespace std;

const int SINK = 50001;
const int MAX_N = 50005;
const int INFINITO = 87654321;

int N, M, P;
int grafo1[MAX_N], grafo2[MAX_N], dist[MAX_N];
list< int > adj[MAX_N];
bool bfs() {
    queue< int > q;

    for (int v = 0; v < N; ++v) {
        if (grafo1[v] == SINK) {
            dist[v] = 0;
            q.push(v);
        }
        else {
            dist[v] = INFINITO;
        }
    }
    dist[SINK] = INFINITO;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (dist[v] < dist[SINK]) {
            for (list< int >::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
                int u = *it;

                if (dist[grafo2[u]] == INFINITO) {
                    dist[grafo2[u]] = dist[v] + 1;
                    q.push(grafo2[u]);
                }
            }
        }
    }
    return dist[SINK] != INFINITO;
}

bool dfs(int u) {
    if (u == SINK) {
        return true;
    }

    for (list< int >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = *it;

        if (dist[grafo2[v]] == dist[u] + 1) {
            if (dfs(grafo2[v])) {
                grafo1[u] = v;
                grafo2[v] = u;
                return true;
            }
        }
    }
    dist[u] = INFINITO;
    return false;
}

int hopcroft_karp() {
    int matching = 0;

    for (int i = 0; i < N; ++i) {
        grafo1[i] = SINK;
    }
    for (int j = 0; j < M; ++j) {
        grafo2[j] = SINK;
    }

    while (bfs()) {
        for (int i = 0; i < N; ++i) {
            if (grafo1[i] == SINK) {
                matching += dfs(i);
            }
        }
    }
    return matching;
}

int rows, cols;
int v[MAX][MAX];
int r[MAX][MAX], c[MAX][MAX];
int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d%d", &rows, &cols);
    for(int i = 0; i <= cols + 1; i++){
      v[0][i] = 2;
      v[rows + 1][i] = 2;
    }
    for(int i = 1; i <= rows; i++){
      v[i][0] = v[i][cols + 1] = 2;
      for(int j = 1; j <= cols; j++)
        scanf("%d", &v[i][j]);
      
    }
    /*
    cout << endl;
    for(int i = 0; i <= rows + 1; i++){
      
      for(int j = 0; j <= cols + 1; j++)
        printf("%3d", v[i][j]);
      cout << endl;
    }
    */
    memset(r, -1, sizeof(r));
    memset(c, -1, sizeof(c));
    int v1 , v2;
    
    int n = 0;
    for(int i = 1; i <= rows; i++){
      int j = 0;
      while(j <= cols){
        //Avanzar 2ses
        while(j <= cols && v[i][j] == 2){
          j++;
        }
        // asigna
        if(j <= cols  && v[i][j] != 2)
          n++;
        while(j <= cols && v[i][j] != 2){
          r[i][j] = n;
          j++;
        }
      }
      
    }
    v1 = n;// numero a la izq
    n = 0;
    for(int i = 1; i <= cols; i++){
      int j = 0;
      while(j <= rows){
        //Avanzar 2ses
        while(j <= rows && v[j][i] == 2){
          j++;
        }
        // asigna
        if(j <= rows  && v[j][i] != 2)
          n++;
        while(j <= rows && v[j][i] != 2){
          c[j][i] = n;
          j++;
        }
      }
      
    }
    v2 = n;// Los nodos estan desde 1 hasta n
    /*
    cout << endl;
    for(int i = 0; i <= rows + 1; i++){ 
      for(int j = 0; j <= cols + 1; j++)
        printf("%3d", r[i][j]);
      cout << endl;
    }
    */
    N = v1, M = v2;
    for(int i = 0; i < N; i++)
      adj[i] = list< int> ();

    for(int i = 1; i <= rows; i++)
      for(int j = 1; j <= cols; j++){
        if(v[i][j] == 0){
          int u = r[i][j], v = c[i][j];
          //          cout << "adiciona " << u << " -  " << v << endl;
          u--; v--;
          adj[u].push_back(v);
        }
      }
    printf("%d\n", hopcroft_karp());
  }
  return 0;
}
