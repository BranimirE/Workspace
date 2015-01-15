#include <cstdio>
#include <iostream>
#include <cstring>

#define MAX 51
using namespace std;
long long int dp[MAX][MAX][MAX];
long long int solve(int n, int k, int m){
  if(n < 0)return 0LL;
  long long int &ans = dp[n][k][m];
  if(k == 1){
    if(n > 0 && n <= m)ans = 1LL;
    else ans = 0LL;
  }
  if(ans != -1)return ans;
  ans = 0LL;
  for(int i = 1; i <= m; i++)
    ans += solve(n-i, k-1, m);
  return ans;
}
int main(){
  int n,k,m;
  memset(dp, -1, sizeof(dp));
  while(scanf("%d%d%d", &n, &k, &m)==3)
    printf("%lld\n", solve(n,k,m));
  return 0;
}
