/*
ID: brani.e2
PROG: skidesign
LANG: C++
 */
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
int n;
int v[1234];
int maxi, mini;
int main() {
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);
  scanf("%d", &n);
  maxi = INT_MIN;
  mini = INT_MAX;
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
    maxi = max(maxi, v[i]);
    mini = min(mini, v[i]);
  }
  if (maxi - mini <= 17) {
    printf("0\n");
    return 0;
  }
  long long ans = LLONG_MAX, tmp;
  for (long long  abajo = 0; abajo + 17 <= 100; abajo++) {
    long long arriba = abajo + 17;
    tmp = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] < abajo)//Subirlo
	tmp += (abajo - v[i]) * (abajo - v[i]);
      if (v[i] > arriba)//Bajarlo
	tmp += (v[i] - arriba) * (v[i] - arriba);
    }
    ans = min(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}
