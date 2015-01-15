#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <assert.h>
using namespace std;
char a[100010], b[100010];
int borrar, cambiar, disponible;
int d[2][100010];
int from, to;
int calcular(int i, int j) {
  if (i == 0 && j == 0)
    return 0;
  int ans = (1 << 28);
  if (i > 0 && j > 0) {
    if (a[i] == b[j])
      ans = min(ans, d[from][j - 1]);
    else
      ans = min(ans, d[from][j - 1] + cambiar);
  }
  if (i > 0)
    ans = min(ans, d[from][j] + borrar);
  if (j > 0)
    ans = min(ans, d[to][j - 1] + borrar);
  assert(ans < (1 << 28));
  return ans;
}
int resolver() {
  if (borrar == 0 && cambiar == 0)
    return 0;
  int n = strlen(a + 1);
  int m = strlen(b + 1);
  
  if (borrar == 0)//Hay que borrar y/o adicionar caracteres
    return 0;
  if (n == m && cambiar == 0)
    return 0;
  /*if ((disponible / borrar) < abs(n - m))
    return -1;*/
  //  int p = (disponible / borrar) + 1;
  int p = disponible;
  from = 0, to = 1;
  fill(d[from], d[from] + n + 1, (1 << 29));
  fill(d[to], d[to] + n + 1, (1 << 29));
  for (int i = 0; i <= m; i++) {
    
    int ini = max(0, i - p), fin = min(n, i + p);
    if ((ini - 1) >= 0)
      d[to][ini - 1] = (1 << 29);
    
    for (int j = ini; j <= fin; j++)
      d[to][j] = calcular(i, j);
    
    swap(from, to);
  }
  if (d[from][n] <= disponible)
    return d[from][n];
  
  return -1;
}
int main() {
  int casos;
  scanf("%d", &casos);

  for (int caso = 1; caso <= casos; caso++) {
    gets(a);
    gets(a + 1);
    gets(b + 1);
    scanf("%d %d %d", &borrar, &cambiar, &disponible);   
    printf("%d\n", resolver());
  }
  return 0;
}
