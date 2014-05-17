#include <iostream>
#include <map>
#include <set>
#define MAX 105
using namespace std;
int value[MAX];
int w[MAX];
typedef pair<int,int> State;
map<State, int> dp;
set<State> indp;
int solve(int id, int free){
  if(id < 0)
    return 0;
  State st(id, free);
  if(indp.count(st))
    return dp[st];
  int ans = solve(id - 1, free); // No take
  if(free >= w[id])
    ans = max(ans, value[id] + solve(id - 1, free - w[id]));
  dp[st] = ans;
  indp.insert(st);
  return ans;
}
int main(){
  int n, free;
  while((cin >> free >> n) && !(free == 0 && n == 0)){
    for(int i = 0; i < n; i++)
      cin >> value[i] >> w[i];
    dp.clear();
    indp.clear();
    cout << solve(n - 1, free) << endl;
  }
  return 0;
}
