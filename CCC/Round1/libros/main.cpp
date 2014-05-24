#include <bits/stdc++.h>
#define MOD 1234567LL
#define MAX 105
using namespace std;
typedef long long int Number;
Number dp[MAX][MAX][MAX][4];
//programacion, musica, ciencia
Number solve(int A, int B, int C, int ultimo){
  if((A + B + C) == 0)
    return 1LL;
  Number &ans = dp[A][B][C][ultimo];
  if(ans != -1)return ans;
  ans = 0;
  if(A && ultimo != 2)
    ans = (ans + solve(A - 1, B, C, 1)) % MOD;
  if(B && ultimo != 1)
    ans = (ans + solve(A, B - 1, C, 2)) % MOD;
  if(C)
    ans = (ans + solve(A, B, C - 1, 3)) % MOD;
  return ans;    
}
int main(){
  int t;
  cin >> t;
  memset(dp, -1, sizeof(dp));
  for(int caso = 1; caso <= t; caso++){
    int P, C, M;
    cin >> P >> C >> M;
    printf("Caso #%d: %lld\n", caso, solve(P, M, C, 0));
  }
  return 0;
}
