#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#define MAX 52
#define INF (1<<29)
using namespace std;
int n;
int tiempo[MAX][MAX], peaje[MAX][MAX];
pair<int,int> dp[MAX][1002], nocalculado = make_pair(-1, -1);
pair<int,int> solve(int actual, int disponible){ // return costo, tiempo
  if(disponible < 0)
    return make_pair(INF,INF);
  pair<int,int> &ans = dp[actual][disponible];
  if(ans != nocalculado)
    return ans;
  if(actual == n-1)
    return ans = make_pair(0, 0);
  ans = make_pair(INF,INF);
  for(int X = 0; X < n; X++)if(X != actual){
    pair<int,int> tmp = solve(X, disponible - tiempo[actual][X]);
    if(peaje[actual][X] + tmp.first < ans.first){
      ans.first = peaje[actual][X] + tmp.first;
      ans.second = tiempo[actual][X] + tmp.second;
    }
  }
  return ans;
}
int main(){
  freopen("in", "r",stdin);
  int tdisp;
  while(scanf("%d%d", &n, &tdisp) and !(!n && !tdisp)){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        scanf("%d", &tiempo[i][j]);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        scanf("%d", &peaje[i][j]);
    // 0 a n-1
    for(int i = 0; i < n; i++)
      for(int j = 0; j <= tdisp; j++)
        dp[i][j] = nocalculado;
    pair<int,int> sol = solve(0, tdisp);
    printf("%d %d\n", sol.first, sol.second);

  }
  return 0;
}
