#include <bits/stdc++.h>

using namespace std;
typedef long long int Number;
Number peso[10005];
map<pair<int, Number>, int> dp;
set<pair<int, Number> > indp;
int solve(int id, Number libre){
  if(id == -1)
    return 0;
  pair<int,Number> state(id, libre);
  if(indp.count(state))
    return dp[state];
  int ans = solve(id - 1, libre);
  if(peso[id] <= libre)
    ans = max(ans, 1 + solve(id - 1, libre - peso[id]));
  dp[state] = ans;
  indp.insert(state);
  return ans;
}
int solve2(int n, Number libre){
  sort(peso, peso + n);
  Number sum = 0;
  int ans = 0;
  int id = 0;
  while(id < n && (sum + peso[id]) <= libre){
    ans++;
    sum += peso[id];
    id++;
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    int n, libre;
    cin >> n >> libre;
    for(int i = 0; i < n; i++)
      cin >> peso[i];
    dp.clear();
    indp.clear();
    cout << solve2(n, libre) << endl;
  }
  return 0;
}
