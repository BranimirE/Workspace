#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

#define MAX 15
#define MOD 20437
#define INF -1
using namespace std;
int n, tam;
char m[MAX][MAX];
int d[MAX][MAX], dp[MAX][MAX];
int dx[4] = {0, 0,-1, 1};
int dy[4] = {1,-1, 0, 0};
pair<int, int> pos[30];
int dist(int ini, int fin){
  queue<pair<int,int> > cola;
  memset(d, INF, sizeof(d));
  int a = pos[ini].first, b = pos[ini].second, x, y;
  d[a][b] = 0;
  cola.push(pos[ini]);
  while(!cola.empty()){
    a = cola.front().first;
    b = cola.front().second;
    cola.pop();
    for(int i = 0; i < 4; i++){
      x = a + dx[i];
      y = b + dy[i];
      if((m[x][y] == '.' || m[x][y] == fin + 'A') && d[x][y] == INF){
        d[x][y] = d[a][b] + 1;
        cola.push(make_pair(x, y));
      }
    }
  }
  return d[pos[fin].first][pos[fin].second];
}

int solve(int i, int j){
  int &ans = dp[i][j];
  if(ans != -1) return ans;

  if(d[i][j] == 0)
    return ans = 1;
  int x, y;
  ans = 0;
  for(int k = 0; k < 4; k++){
    x = i + dx[k];
    y = j + dy[k];
    if(d[x][y] == d[i][j] - 1)
      ans += solve(x, y);
  }
  return ans % MOD;
}

int camin(int ini, int fin){
  int a = pos[ini].first, b = pos[ini].second;
  int x = pos[fin].first, y = pos[fin].second;
  memset(dp, -1, sizeof(dp));
  m[a][b] = m[x][y] = '.';
  return solve(x, y);
}
int main(){
  freopen("in", "r", stdin);
  memset(m[0], '#', sizeof(m[0]));
  int caso = 1;
  while(scanf("%d", &n) && n){
    getchar();
    memset(m[n + 1], '#', sizeof(m[n + 1]));
    tam = 0;
    for(int i = 1; i <= n; i++){
      gets(m[i] + 1);
      for(int j = 1; j <= n; j++)
      if(isalpha(m[i][j])){
        int car = m[i][j] - 'A';
        pos[car].first = i;
        pos[car].second = j,
        tam++;
      }
      m[i][0] = m[i][n + 1] = '#';
    }
    int distancia = 0;
    int caminos = 1;
    for(int i = 1; i < tam; i++){
      int tmp = dist(i - 1, i);
      if(tmp == INF){
        distancia = INF;
        break;
      }
      distancia += tmp;
      caminos = (caminos * camin(i - 1, i)) % MOD;

    }
    printf("Case %d: ", caso++);
    if(distancia == INF)
      puts("Impossible");
    else
      printf("%d %d\n", distancia, caminos);
  }
  return 0;
}
