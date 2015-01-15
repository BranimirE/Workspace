#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

#define MAX 205

using namespace std;

int d[257];
int f, c, tmp;
bool m[MAX][MAX];
bool v[MAX][MAX];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool isvalid(int i, int j) {
  return (i>=0 && i<=f+1 && j>=0 && j<=c+1 && !v[i][j]);
}
void dfs(int i, int j) {
  if(v[i][j])return;
  v[i][j] = true;
  for(int k = 0; k < 4; k++) {
    int x = i + dx[k], y = j + dy[k];
    if(isvalid(x,y) && m[x][y] == 0)//solo para recorrer blancos
      dfs(x,y);
  }
}
int huecos;
void solve(int i, int j) {
  if(v[i][j])return;
  v[i][j] = true;
  for(int k = 0; k < 4; k++) {
    int x = i + dx[k], y = j + dy[k];
    if(isvalid(x,y)){
      if(m[x][y] == 0){
        dfs(x,y);
        huecos++;
      }else
        solve(x,y);
    }
  }
}
int main() {
  for(int i = 0; i < 10; i++) {
    d['0' + i] = i;
    d['a' + i] = 10 + i;
  }
  int caso = 1;
  while(scanf("%d%d", &f, &tmp) and !(f == 0 && tmp == 0)) {
    getchar();
    c = tmp * 4;
    memset(m, 0, sizeof(m));
    for(int i = 1; i <= f; i++) {
      for(int j = 0, pos = 1; j < tmp; j++, pos += 4) {
        int t = d [getchar()];
        for(int k = 0; k < 4; k++)
          m[i][pos+k] = (1<<(3-k)) & t;
      }
      getchar();
    }
    memset(v, 0, sizeof(v));
    dfs(0,0); // marcamos todos los blancos de los alrededores
    string ans = "";

    for(int i = 1; i <= f; i++)
      for(int j = 1; j <= c; j++)
        if(m[i][j] == 1 && !v[i][j]) {
          huecos = 0;
          solve(i, j);
          if(huecos == 0) ans += 'W';
          if(huecos == 1) ans += 'A';
          if(huecos == 2) ans += 'K';
          if(huecos == 3) ans += 'J';
          if(huecos == 4) ans += 'S';
          if(huecos == 5) ans += 'D';
        }
    sort(ans.begin(), ans.end());
    printf("Case %d: %s\n", caso++, ans.c_str());
  }
  return 0;
}
