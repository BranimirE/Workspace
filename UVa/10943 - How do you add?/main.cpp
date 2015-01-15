#include <cstdio>
#include <fstream>
#include <cstring>

#define MOD 1000000
#define MAX 101

using namespace std;
int dp[MAX][MAX];
int solve(int n, int k){
  if(k == 1)return 1;
  int &ans = dp[n][k];
  if(ans != -1)return ans;
  ans = 0;
  for(int i = 0; i <= n; i++)
    ans = (ans + solve(n-i, k-1)) % MOD;
  return ans;
}
int main(){
  //freopen("in", "r", stdin);
  int n,k;
  memset(dp, -1, sizeof(dp));
  while(scanf("%d%d", &n, &k), !(n==0 && k==0))
    printf("%d\n", solve(n,k));
  return 0;
}
