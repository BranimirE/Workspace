#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
vector<int> g[MAX];
bool tovisit[MAX];
int n, m, s, t, k;
int dp[MAX][MAX];
int solve(int u, int visited){
  int &ans = dp[u][visited];
  if(ans != -1) return ans;
  if(u == t)
    return ans = visited == k;
  int ways = 0;
  for(int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    ways += solve(v, visited + tovisit[v]);
  }
  return ans = ways;
}
int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
      g[i].clear();

    for(int i = 0; i < m; i++){
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
    }
    scanf("%d%d%d", &s, &t, &k);
    memset(tovisit, false, sizeof(tovisit));
    for(int i = 0; i < k; i++){
      int tmp;
      scanf("%d", &tmp);
      tovisit[tmp] = true;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(s, 0));
  }
  return 0;
}
