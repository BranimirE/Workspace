#include <cstdio>
#include <algorithm>
using namespace std;
int n, q, k;
int v[(int)1e6 + 5];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", &v[i]);
  scanf("%d", &q);
  while(q--){
    scanf("%d", &k);
    int ans = 0;
    for(int i = 0; i < n; i++)
      for(int j = i ; j < n; j++)
        if(*min_element(v + i, v + j + 1) == k)
          ans++;
    printf("%d\n", ans);
  }
  return 0;
}
