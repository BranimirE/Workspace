#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
char a[100010], b[100010];
int borrar, cambiar, disponible;
int r[100010];
/*int calcular(int i, int j) {
  if (i == 0 && j == 0)
    return 0;
  int ans = (1 << 30);
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
  return ans;
  }*/
int resolver() {
  if (borrar == 0 && cambiar == 0)
    return 0;
  int n = strlen(a + 1);
  int m = strlen(b + 1);
 
  if (borrar == 0)//Hay que borrar y/o adicionar caracteres
    return 0;
  if (n == m && cambiar == 0)
    return 0;
  if ((disponible / borrar) < abs(n - m))
    return -1;
  fill(r, r + 100010, (1 << 29));
  int p = ((disponible / borrar) - abs(n - m)) / 2;
  int kprima, k;
  kprima = k = ((n>=m)?(-p):(-p + (n - m)));
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= (abs(n - m) + 2 * p); j++) {
      if (i == (j + k) && (j + k) == 0)
	r[j] = 0;
      else {
	r[j] = min(r[j] + ((a[i] == b[j + k])?0:cambiar),
		   min(r[j + 1] + borrar ,
		       r[j - 1] + borrar));
      }
    }
    k++;
  }
  int ans = r[abs(n - m) + 2 * p + kprima];
  if (ans <= disponible)
    return ans;
  return -1;
}
int main() {
  int casos;
  scanf("%d", &casos);
  for (int caso = 1; caso <= casos; caso++) {
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    scanf("%d %d %d", &borrar, &cambiar, &disponible);   
    printf("%d\n", resolver());
  }
  return 0;
}
