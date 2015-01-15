/*
ID: brani.e2
PROG: skidesign
LANG: C++
 */
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long int Number;
int n;
int v[1234];
int main() {
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v + n);
  if ((v[n - 1] - v[0]) <= 17) {
    printf("0\n");
    return 0;
  }
  long long int ans = 1LL<<59LL, tmp;
  for (int i = v[0]; i <= v[n-1] - 17; i++) {
    int bottom = i, top = i + 17;
    tmp = 0;
    for (int j = 0; j < n && v[j] < bottom; j++) {
      tmp += Number(bottom - v[j]) * Number(bottom - v[j]);
    }
    for (int j = n - 1; j >= 0 && top < v[j]; j--) {
      tmp += Number(v[j] - top) * Number (v[j] - top);
    }
    ans = min(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}
