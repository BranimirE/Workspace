#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXF 11
#define MAXC 101
int v[MAXF][MAXC];
int p[MAXF][MAXC];
int o[3];
int main() {
  //freopen("in", "r", stdin);
  int filas, cols, x, y, z;
  while(scanf("%d%d", &filas, &cols) == 2) {
    for(int i = 0; i < filas; i++)
      for(int j = 0; j < cols; j++)
        scanf("%d", &v[i][j]);
    for(int c = cols-2; c >= 0; c--)
      for(int r = 0; r < filas; r++){
        int mejor = r;
        for(int k = -1; k <= 1; k++){
          int pos = (r+filas+k)%filas;
          if(v[pos][c+1] < v[mejor][c+1] || (v[pos][c+1] == v[mejor][c+1] && pos < mejor))
            mejor = pos;
        }
        v[r][c] += v[mejor][c+1];
        p[r][c] = mejor;
      }
    int pos = 0, sol;
    for(int i = 0; i < filas; i++)
      if(v[i][0] < v[pos][0])
        pos = i;
    sol = v[pos][0];
    printf("%d", pos+1);
    for(int col = 0; col < cols-1; col++){
      pos = p[pos][col];
      printf(" %d", pos+1);
    }
    puts("");
    printf("%d\n", sol);
  }
  return 0;
}
