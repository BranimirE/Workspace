#include <bits/stdc++.h>
#define MAX 65
#define MAXMASK 1048676
using namespace std;
vector<int> g[MAX];
int n, m;
int dp[MAXMASK];
int solve(int mask){
  if(dp[mask] != -1)
    return dp[mask];
  int ans = 0;
  for(int i = 0; i < n; i++){
    if((mask &(1 << i)) == 0){
      bool cantake = true;
      for(int j = 0; j < g[i].size() && cantake; j++)
        cantake = ((mask & (1 << g[i][j])) == 0);
      if(cantake){
        ans = max(ans, 1 + solve(mask | (1 << i)));
      }
    }
  }
  return dp[mask] = ans;
}
int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
      g[i].clear();
    for(int i = 0; i < m; i++){
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0));
  }
  return 0;
}
