#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1002
int k, n, m, v[MAX], c[MAX][MAX], b[MAX][MAX];
pair<int,int> g[MAX];
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
      scanf("%d", &v[i]);
      v[i]--;
      g[i].second = i;
    }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        scanf("%d", &b[i][j]);

    for(int i = 0; i < n; i++){
      int tmp = b[i][v[i]];
      for(int j = 0; j < m; j++){
        scanf("%d", &c[i][j]);
        tmp = max(tmp, b[i][j] - c[i][j]);
      }
      g[i].first = tmp - b[i][v[i]];
    }
    sort(g, g + n);
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
      ans += b[g[i].second][v[g[i].second]];
      if(k){
        ans += g[i].first;
        k--;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
