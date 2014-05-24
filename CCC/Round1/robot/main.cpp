#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
int n;
int x[22], y[22], e[22];
/*
int dp[(1<<7)][22][500];
int solve(int vis, int pos, int energia){
  //  cout << "esta en " << pos << " con energia = " << energia << endl;
  int &ans = dp[vis][pos][energia];
  if(ans != -1) return ans;
  energia += e[pos];//reabastesco
  ans = abs(x[pos]) + abs(y[pos]) + energia;//me alejo con esta energia

  // Intento reabastecerme
  for(int i = 1; i <= n; i++)
    if((vis & (1 << i)) == 0){//No use este
      int dist = abs(x[i] - x[pos]) + abs(y[i] - y[pos]);
      if(dist <= energia)//puedo llegar
        ans = max(ans, solve(vis | (1 << i), i, energia - dist));
    }
  return ans;
  }*/
int ans;
void solve(int pos, int energia){
  int tmp = e[pos];
  e[pos] = 0;
  energia += tmp;
  ans = max(ans, energia + abs(x[pos]) + abs(y[pos]));
  for(int i = 1; i <= n; i++){
    int dist = abs(x[i] - x[pos]) + abs(y[i] - y[pos]);
    if(e[i] && dist <= energia)
      solve(i, energia - dist);
  }
  e[pos] = tmp;
}
int main(){
  int t;
  cin >> t; 
  for(int caso = 1; caso <= t; caso++){
    int energia;
    cin >> energia >> n;
    x[0] = y[0] = 0;
    e[0] = energia;
    for(int i = 1; i <= n; i++)
      cin >> x[i] >> y[i] >> e[i];
    //  memset(dp, - 1, sizeof(dp));
    //    printf("Caso #%d: %d\n", caso, solve(1, 0));
    ans = 0;
    solve(0, 0);
    printf("Caso #%d: %d\n", caso, ans);
  }
  return 0;
}
