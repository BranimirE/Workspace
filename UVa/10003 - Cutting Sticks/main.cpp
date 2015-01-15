#include <cstdio>
#include <fstream>
#include <cstring>
#define MAX 51
using namespace std;
int l, n;
int c[MAX];
int dp[MAX][MAX];
int solve(int izq, int der){
  if(izq + 1 == der)return 0;// no hay que cortar nada
  int &ans = dp[izq][der];
  if(ans != -1) return ans;
  ans = 1<<30;
  for(int i = izq + 1; i < der; i++)
    ans = min(ans, (c[der]-c[izq]) + solve(izq, i) + solve(i, der));
  return ans;
}
int main() {
  //freopen("in", "r", stdin);
  while(scanf("%d", &l), l) {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
      scanf("%d", &c[i]);
    c[0] = 0; c[n + 1] = l;
    memset(dp, -1, sizeof(dp));
    printf("The minimum cutting is %d.\n", solve(0, n + 1));
  }
  return 0;
}
