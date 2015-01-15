#include <bits/stdc++.h>
using namespace std;
#define MAX 5500
#define INF 1000000000

vector<int> g[MAX];
vector<int> p;
int res[MAX][MAX], mf, f, s, t;

void augment(int v, int minEdge){
  if(v == s){
    f = minEdge;
    return;
  }else if(p[v] != -1){
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
}
int rows, cols, banks;
int in(int i, int j){return i * rows + j;}
int out(int i, int j){return in(i, j) + rows * cols;}
int dx[4] = { 0, 0,-1, 1};
int dy[4] = {-1, 1, 0, 0};
bool bank[55][55];
int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d%d%d", &rows, &cols, &banks);
    rows += 2;
    cols += 2;
    s = rows * cols * 2;
    t = s + 1;
    for(int i = 0; i <= t; i++)
      g[i].clear();
    memset(res, 0, sizeof(res));
    memset(bank, false, sizeof(bank));
    bool ispossible = true;
    for(int i = 0; i < banks; i++){
      int x, y;
      scanf("%d%d", &x, &y);

      if(bank[x][y])
        ispossible = false;
      bank[x][y] = true;

      g[s].push_back(in(x, y));
      res[s][in(x, y)] = 1;
    }
    if(!ispossible){
      printf("not possible\n");
      continue;
    }
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        g[in(i, j)].push_back(out(i, j));
        res[in(i, j)][out(i, j)] = 1;
        
        if(i == 0 || j == 0 || i == (rows - 1) || j == (cols - 1)){
          g[out(i, j)].push_back(t);
          res[out(i, j)][t] = 1;
        }

        for(int k = 0; k < 4; k++){
          int ni = i + dx[k], nj = j + dy[k];
          if(ni >= 0 && ni < rows && nj >= 0 && nj < cols){
            g[out(i, j)].push_back(in(ni, nj));
            res[out(i, j)][in(ni, nj)] = 1;
          }
        }
      }
    }
    
    mf = 0;
    while(true){
      f = 0;
      bitset<MAX> vis; vis[s] = true;
      queue<int> q; q.push(s);
      p.assign(MAX, -1);
      while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == t) break;
        for(int j = 0; j < g[u].size(); j++){
          int v = g[u][j];
          if(res[u][v] > 0 && !vis[v])
            vis[v] = true, q.push(v), p[v] = u;
        }
      }
      augment(t, INF);
      if(f == 0) break;
      mf += f;
    }
    printf(mf==banks?"possible\n":"not possible\n");
  }
  return 0;
}
