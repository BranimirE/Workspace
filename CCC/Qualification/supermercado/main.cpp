#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int cost[1005];
int dp[1005][100005];
int solve(int pos, int money){
  if(pos == n)
    return 0;
  int &ans = dp[pos][money];
  if(ans != -1) return ans;

  ans = solve(pos + 1, money); //No buy
  if(money >= cost[pos])
    ans = max(ans, cost[pos] + solve(pos + 1, money - cost[pos]));//buy
  return ans;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    int money;
    cin >> money >> n;
    for(int i = 0; i < n; i++)
      cin >> cost[i];
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, money));
  }
  return 0;
}
