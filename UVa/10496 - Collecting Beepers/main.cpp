#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>

#define MAX 13
using namespace std;
pair<int,int> v[MAX];
int d[MAX][MAX];
int dp[MAX][1<<MAX];
int n;
int solve(int pos, int mask){
  int &ans = dp[pos][mask];
  if(ans != -1)return ans;
  if(mask == ((1<<n)-1)) // todos visitados
    return ans = d[pos][0];// volver al principio
  ans = 1<<30;
  for(int i = 0; i < n; i++)
    if(~mask & (1<<i))
      ans = min(ans, d[pos][i+1] + solve(i+1, mask|(1<<i)));
  return ans;
}
int main(){
  freopen("in", "r", stdin);
  int t, x, y;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &x, &y);
    scanf("%d%d", &v[0].first, &v[0].second);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      scanf("%d%d", &v[i].first, &v[i].second);
    for(int i = 0; i <=n; i++)
      for(int j = 0; j <= n; j++)
        d[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
    memset(dp, -1, sizeof(dp));
    printf("The shortest path has length %d\n", solve(0, 0));
  }
  return 0;
}
