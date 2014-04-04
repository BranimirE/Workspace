#include <cstdio>
#include <cstring>
#define MAXN 20005
#define MAXM 21
#define max(a,b) (a>b?a:b)
using namespace std;
int n, m, tmp, ans;
int k[MAXN];
int v[MAXM][MAXN];
int con[MAXM];
bool sw[MAXN];
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &k[i]);
    for(int j = 0; j < k[i]; j++)
      scanf("%d", &v[i][j]);
  }
  for(int i = 0; i < m; i++)
    for(int j = i + 1; j < m; j++){
      memset(sw, false, sizeof(sw));
      for(int x = 0; x < k[i]; x++)
        sw[v[i][x]] = true;
      for(int x = 0; x < k[j]; x++)
        if(sw[v[j][x]]){
          con[i] |= (1<<j);
          con[j] |= (1<<i);
          break;
        }
    }
  ans = 0;
  for(int mask = 0; mask < (1<<m); mask++){
    int ones = __builtin_popcount(mask);
    if(ones > ans){
      int tmp = 0;
      for(int i = 0; i < m; i++)
        if(mask & (1 << i))
          tmp |= con[i];
      if((tmp & mask) == 0) ans = ones;
    }
  }
  printf("%d\n", ans);
  return 0;
}
