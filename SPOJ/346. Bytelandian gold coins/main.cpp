#include <cstdio>
#include <map>

#define max(a,b) (((a)>(b))?(a):(b))
typedef long long int Number;
using namespace std;
map<Number,Number> dp;
Number solve(Number n){
  if(n == 0)
    return 0;
  Number ans = dp[n];
  if(ans) return ans;
  ans = max(n, solve(n/2) + solve(n/3) + solve(n/4));
  return dp[n] = ans;
}
int main(){
  int coin;
  while(scanf("%d", &coin) != EOF)
    printf("%lld\n", solve(coin));
  return 0;
}
