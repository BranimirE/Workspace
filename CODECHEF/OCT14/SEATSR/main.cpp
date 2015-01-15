#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
char a[100010], b[100010];
int borrar, cambiar, disponible;
int d[1000][1000];
int calcular(int i, int j) {
  if (i == 0 && j == 0)
    return 0;
  int ans = (1 << 30);
  if (i > 0 && j > 0) {
    if (a[i] == b[j])
      ans = min(ans, d[i - 1][j - 1]);
    else
      ans = min(ans, d[i - 1][j - 1] + cambiar);
  }
  if (i > 0)
    ans = min(ans, d[i - 1][j] + borrar);
  if (j > 0)
    ans = min(ans, d[i][j - 1] + borrar);
  return ans;
}
int resolver() {
  if (borrar == 0 || cambiar == 0)
    return 0;
  int n = strlen(a + 1);
  int m = strlen(b + 1);

  if ((disponible / borrar) < abs(n - m))
    return -1;
  int p = ((disponible / borrar) - abs(n - m)) / 2;
  for (int i = 0; i <= m; i++) {
    fill(d[i], d[i] + n + 1, (1 << 30));
    if (n >= m) {
      for (int j = max(0, i - p); j <= min(n, i + (n - m) + p); j++)
	d[i][j] = calcular(i, j);
    } else {
      for (int j = max(0, i + (n - m) - p); j <= min(n, i + p); j++) {
	d[i][j] = calcular(i, j);
      }
    }
  }
  if (d[m][n] <= disponible) return d[m][n];
  return -1;
}
int main() {
  int casos;
  scanf("%d", &casos);
  for (int caso = 1; caso <= casos; caso++) {
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    scanf("%d %d %d", &borrar, &cambiar, &disponible);
    cout << (a + 1) << " " << (b + 1) << endl;
    
    printf("%d\n", resolver());
  }
  return 0;
}
