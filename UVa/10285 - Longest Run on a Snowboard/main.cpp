#include <cstdio>
#include <fstream>
#include <cstring>

#define MAX 103
using namespace std;
int filas, cols, v[MAX][MAX];
char pista[1000];
int dp[MAX][MAX];
int dx[4] = { 0,0,-1,1};
int dy[4] = {-1,1, 0,0};
bool isvalid(int i, int j){
  return i>=0 && i < filas && j >= 0 && j < cols;
}
int solve(int i, int j){
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = 1;
  for(int k = 0; k < 4; k++){
    int a = i + dx[k];
    int b = j + dy[k];
    if(isvalid(a, b) && v[a][b] < v[i][j])
      ans = max(ans, 1 + solve(a, b));
  }
  return ans;
}
int main(){
  freopen("in", "r", stdin);
  int n;
  scanf("%d", &n);
  while(n--){
    scanf("%s %d %d", pista, &filas, &cols);
    for(int i = 0; i < filas; i++)
      for(int j = 0; j < cols; j++)
        scanf("%d", &v[i][j]);
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < filas; i++)
      for(int j = 0; j < cols; j++)
        if(dp[i][j] == -1)
          ans = max(ans, solve(i, j));
    printf("%s: %d\n", pista, ans);
  }
  return 0;
}
