#include <iostream>
#include <fstream>
#include <cstring>

#define MAXN 1002
#define oo 1<<30
using namespace std;
int v[10][MAXN];
int dp[10][MAXN];
int recorrer;
int solve(int altura, int milla){
  if(altura > 9 || altura < 0) return oo;
  if(altura > recorrer - milla) return oo;
  if(milla == recorrer) return 0;
  int &ans = dp[altura][milla];
  if(ans != -1)return ans;
  int subir    = solve(altura + 1, milla + 1) + 60;
  int mantener = solve(altura    , milla + 1) + 30;
  int bajar    = solve(altura - 1, milla + 1) + 20;
  return ans = min(subir, min(mantener, bajar)) + ((-1) * v[altura][milla]);
}
int main() {
  //freopen("in", "r", stdin);
  int t;
  cin >> t;
  while(t--) {
    cin >> recorrer;
    recorrer /= 100;
    for(int i = 9; i >= 0; i--)
      for(int j = 0; j < recorrer;j++)
        cin >> v[i][j];
    memset(dp, -1, sizeof(dp));
    cout << solve(0,0) << endl<<endl;
  }
  return 0;
}
