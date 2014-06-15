#include <bits/stdc++.h>

using namespace std;
int n, mov;
vector<int> fichas;
int dp[100000+5];
bool solve(int cant){
  if(cant <= 0)return false;// No puedo jugar "pierdo" :(
  if(dp[cant] != -1)return dp[cant];
  for(int i = 0; i < fichas.size() && cant >= fichas[i]; i++)
    if(solve(cant - fichas[i]) == false)// pierde el otro ? :D
      return dp[cant] = 1;
  return dp[cant] = 0;// No pude hacer ninguna jugada pierdo :'(
}
int main() {
  int t;
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    cin >> n >> mov;
    fichas.clear();
    for(int i = 0; i < mov; i++){
      int tmp;
      cin >> tmp;
      fichas.push_back(tmp);
    }
    sort(fichas.begin(), fichas.end());
    memset(dp, -1, sizeof(dp));
    printf("Caso #%d: %s\n", caso, solve(n)?"SI":"NO");
  }
  return 0;
}
