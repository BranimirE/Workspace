#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()

char a[100010], b[100010];
int borrar, cambiar, disponible;
int d[2][100010];
int from, to;
int n, m;
int resolver() {
  if (borrar == 0)return 0;
  if (n == m && cambiar == 0) return 0;
  from = 0, to = 1;
  fill(d[0], d[0] + m + 1, (1<<29));
  fill(d[1], d[1] + m + 1, (1<<29));
  int desplazamiento = disponible / borrar;
  for (int i = 0; i <= n; i++) {
    int ini = max(0, i - desplazamiento), fin = min(m, i + desplazamiento);   
    for (int j = ini; j <= fin; j++) {
      int &ans = d[to][j];
      if (i == 0)
	ans = j * borrar;
      else if (j == 0)
	ans = i * borrar;
      else {	
	if (a[i] == b[j])
	  ans = d[from][j - 1];
	else
	  ans = d[from][j - 1] + cambiar;
	ans = min(ans, d[from][j] + borrar);
	ans = min(ans, d[to][j - 1] + borrar);
      }
    }
    swap(from, to);
  }
  if (d[from][m] > disponible)
    return -1;
  return d[from][m];
}
int main() {
  int casos;
  scanf("%d", &casos);
  for (int caso = 1; caso <= casos; caso++) {
    scanf("%s %s", a + 1, b + 1);
    scanf("%d %d %d", &borrar, &cambiar, &disponible);
    n = strlen(a + 1);
    m = strlen(b + 1);    
    printf("%d\n", resolver());
  }
  return 0;
}
