#include <algorithm>
#include <cstring>
#include <cstdio>
#include <limits>
#include <queue>
#include <vector>
using namespace std;
 
#define N 5500
#define MAX 5500

int cap[N][N], padre[N], n, s, t;
vector<int> g[MAX];
bool bfs() {
  queue<int> q;
  q.push(s);
  memset(padre, -1, sizeof padre);
  padre[s] = s;
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (u == t)
      return true;
    for(int i = 0; i < g[u].size(); i++){
      int v = g[u][i];
      if (padre[v] == -1 && cap[u][v])
        padre[v] = u, q.push(v);
    }
  }
  return false;
}
 
int maxFlow() {
  int mf = 0, f, v;
  while(bfs()) {
    v = t;
    f = numeric_limits<int>::max();
    while (padre[v] != v)
      f = min(f, cap[padre[v]][v]), v = padre[v];
    v = t;
    mf += f;
    while (padre[v] != v)
      cap[padre[v]][v] -= f, cap[v][padre[v]] += f, v = padre[v];
  }
  return mf;
}
 
int rows, cols, banks;
int in(int i, int j){
  return i * rows + j;
}
int out(int i, int j){
  return in(i, j) + (rows * cols);
}
int dx[4] = {0 , 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool bank[55][55];
int main() {
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d%d%d", &rows, &cols, &banks);
    rows += 2;
    cols += 2;    
    n = rows * cols * 2;
    s = n;
    t = n + 1; 
    memset(cap, 0, sizeof(cap));
    for(int i = 0; i < n + 2; i++)
      g[i].clear();
    memset(bank, false, sizeof(bank));
    bool possible = true;
    for(int i = 0; i < banks; i++){
      int x, y;
      scanf("%d%d", &x, &y);
      if(bank[x][y])
        possible = false;
      bank[x][y] = true;
      g[s].push_back(in(x, y));
      g[in(x, y)].push_back(s);
      cap[s][in(x, y)] = 1;
    }
    if(!possible){
      printf("not possible\n");
      continue;
    }
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        g[in(i, j)].push_back(out(i, j));
        g[out(i, j)].push_back(in(i, j));
        cap[in(i, j)][out(i, j)] = 1;
        for(int k = 0; k < 4; k++){
          int ii = i + dx[k], jj = j + dy[k];
          if(ii >= 0 && ii < rows && jj >= 0 && jj < cols){
            g[out(i, j)].push_back(in(ii,jj));
            g[in(ii,jj)].push_back(out(i, j));
            cap[out(i, j)][in(ii, jj)] = 1;
          }
        }
        if(i == 0 || j == 0 || i == (rows - 1) || j == (cols - 1)){
          g[out(i, j)].push_back(t);
          g[t].push_back(out(i, j));
          cap[out(i, j)][t] = 1;
        }
      }
    }
    /*
    puts("Mostrando IN");
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        printf("%3d", in(i, j));
      }
      puts("");
    }
    puts("Mostrando OUT");
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++)
        printf("%3d", out(i, j));
      puts("");
    }
    
    puts("Mostrando el grafo");
    for(int i = 0; i <= t; i++){
      printf("%d : ", i);
      for(int j = 0; j < g[i].size(); j++)
        printf("%d ", g[i][j]);
      puts("");
      }*/
    int maxf = maxFlow();
    printf((maxf == banks )?"possible\n":"not possible\n");
  }
  return 0;
}
