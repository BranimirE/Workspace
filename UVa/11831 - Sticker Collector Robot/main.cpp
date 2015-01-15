#include <cstdio>
#include <fstream>
#include <cstring>

#define MAX 105
using namespace std;
int filas, cols, len;
char m[MAX][MAX], c[50005];
int dx[4] = { 0, 1, 0,-1};// N, E, S, O - columna
int dy[4] = {-1, 0, 1, 0};// 0, 1, 2, 3 - fila

int main() {
  //freopen("in", "r",stdin);
  while(scanf("%d%d%d", &filas, &cols, &len) and !(filas == 0 and cols == 0 and len == 0)) {
    getchar();// para el \n
    for(int i = 0; i <= cols + 1; i++)
      m[0][i] = m[filas+1][i] = '#';
    int dir = 0, x, y; // columna, fila
    for(int i = 1; i <= filas; i++) {
      m[i][0] = '#';
      gets(m[i] + 1);
      m[i][cols + 1] = '#';
      for(int j = 1; j <= cols; j++)
        if(isalpha(m[i][j])) {
          if(m[i][j] == 'N') dir = 0;
          if(m[i][j] == 'L') dir = 1;
          if(m[i][j] == 'S') dir = 2;
          if(m[i][j] == 'O') dir = 3;
          y = i;
          x = j;
        }
    }
    gets(c);
    int ans = 0;
    for(int i = 0; i < len; i++) {
      if(c[i] == 'D')
        dir = (dir + 1) % 4;
      if(c[i] == 'E')
        dir = (dir - 1 + 4) % 4;
      if(c[i] == 'F'){
        int a = x + dx[dir];//col
        int b = y + dy[dir];//fila
        if(m[b][a] != '#'){
          x = a;
          y = b;
          if(m[y][x] == '*'){
            ans++;
            m[y][x] = '.';
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
