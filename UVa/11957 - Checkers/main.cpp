#include <cstdio>
#include <fstream>
#include <cstring>

#define MAX 105
#define MOD 1000007
using namespace std;
int n;
char m[MAX][MAX];
int dp[MAX][MAX];
bool isvalid(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < n && (m[i][j] == '.' || m[i][j] == 'W');
}
int solve(int i, int j){
  int &ans = dp[i][j];
  if(ans != -1) return ans;

  if(m[i][j] == 'W')
    return ans = 1;
  ans = 0;
  int a, b;
  a = i + 1, b = j + 1;
  if(isvalid(a, b))
    ans += solve(a, b);
  else {
      a = i + 2, b = j + 2;
      if(isvalid(a, b)) ans += solve(a, b);
  }
  a = i + 1 , b = j - 1;
  if(isvalid(a, b))
    ans += solve(a, b);
  else {
      a = i + 2, b = j - 2;
      if(isvalid(a, b)) ans += solve(a, b);
  }
  ans %= MOD;
  return ans;
}
int main(){
  freopen("in", "r", stdin);
  int t;
  scanf("%d", &t);
  for(int caso = 1; caso <= t; caso++){
    scanf("%d", &n);getchar();
    for(int i = 0; i < n; i++)
      gets(m[i]);

    memset(dp, -1, sizeof(dp));
    int sol = 0;
    for(int i = 0; i < n; i++)
      if(m[0][i] == '.')
        sol = (sol + solve(0, i)) % MOD;
    printf("Case %d: %d\n", caso, sol);
  }
  return 0;
}
