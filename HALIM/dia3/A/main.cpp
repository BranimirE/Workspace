#include <bits/stdc++.h>
using namespace std;
#define INF (1<<29)
int v[100005][3];
int n;
int dp[100005][4][4][4];
int solve(int pos, int a, int b, int ini){
  if(pos >= n) return 0;
  int &ans = dp[pos][a][b][ini];
  if(ans != -1)return ans;
  if(pos == n - 1){
    ans = -INF;
    for(int c = 0; c  < 3; c++){
      if((a > b && c > b) || (a < b && c < b) ){
        if((b > c && ini > c) || (b < c && ini < c))
          ans = max(ans, v[pos][c]);
      }
    }    
    return ans;
  }

  ans = 0;
  for(int c = 0; c  < 3; c++){
    if((a > b && c > b) || (a < b && c < b)){
      ans = max(ans,v[pos][c] + solve(pos + 1, b, c, ini));       
    }
  }
  return ans;
}
int main(){
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < 3; j++)
        scanf("%d", &v[i][j]);

    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(i != j){
          ans = max(ans, v[0][i] + v[1][j] + solve(2, i, j, i));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
